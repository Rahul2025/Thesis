/* 
	given a list of C/C++/Java/Python/Haskell files on the command line, count the LOC in each...  
   LOC = physical, non-comment lines.....
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/* Modes */
#define NORMAL 0
#define INSTRING 1
#define INCOMMENT 2

/* Types of comments: */
#define ANSIC_STYLE 0
#define CPP_STYLE 1

#define BOOLEAN int
#define TRUE 1
#define FALSE 0


/* Globals */
long total_sloc;

static BOOLEAN warn_embedded_newlines = FALSE;

int peek(FILE *stream) {
 int c = getc(stream);
 ungetc(c, stream);
 return c;
}

int ispeek(int c, FILE *stream) {
 if (c == peek(stream)) {return 1;}
 return 0;
}

long line_number;

int getachar(FILE *stream) {
 static BOOLEAN last_char_was_newline = 0;
 int c;

 c = getc(stream); 
 if (last_char_was_newline) line_number++;
 if (c == '\n') last_char_was_newline=1;
 else           last_char_was_newline=0;
 return c;
}


long sloc_count(char *filename, FILE *stream) {

 long sloc = 0;

 int sawchar = 0;                
 int c;
 int mode = NORMAL;            
 int comment_type = ANSIC_STYLE;

 while ( (c = getachar(stream)) != EOF) {
   if      (mode == NORMAL) {
     if (c == '"') {sawchar=1; mode = INSTRING;}
     else if (c == '\'') { 
       sawchar=1;
       c = getachar(stream);
       if (c == '\\')  c = getachar(stream);
       do {
         c = getachar(stream);
       } while ((c != '\'') && (c != '\n') & (c != EOF));
     } else if ((c == '/') && ispeek('*', stream)) {
          c = getachar(stream);
          mode = INCOMMENT;
          comment_type = ANSIC_STYLE;
     } else if ( ((c == '/') && ispeek('/', stream)) || ((c == '-') && ispeek('-', stream)) ) {
          c = getachar(stream);
          mode = INCOMMENT;
          comment_type = CPP_STYLE;
     } else if (!isspace(c)) {sawchar = 1;}
   } else if (mode == INSTRING) {
 
     if (!isspace(c)) sawchar = 1;
     if (c == '"') {mode = NORMAL;}
     else if ((c == '\\')  && (ispeek('\"', stream) || ispeek('\\', stream))) {c = getachar(stream);}
     else if ((c == '\\')  && ispeek('\n', stream)) {c = getachar(stream);}
     else if ((c == '\n') && warn_embedded_newlines) {
  
       fprintf(stderr, "c_count WARNING - newline in string, line %ld, file %s\n", line_number, filename);
     
     }
   } else {  /* INCOMMENT mode */
     if ((c == '\n') && (comment_type == CPP_STYLE)) { mode = NORMAL;}
     if ((comment_type == ANSIC_STYLE) && (c == '*') &&
          ispeek('/', stream)) { c= getachar(stream); mode = NORMAL;}
   }
   if (c == '\n') {
     if (sawchar) sloc++;
     sawchar = 0;
   }
 
 }
 if (sawchar) sloc++;
 sawchar = 0;
 if ((mode == INCOMMENT) && (comment_type == CPP_STYLE)) { mode = NORMAL;}

 if (mode == INCOMMENT) {
     fprintf(stderr, "c_count ERROR - terminated in comment in %s\n", filename);
 } else if (mode == INSTRING) {
     fprintf(stderr, "c_count ERROR - terminated in string in %s\n", filename);
 }

 return sloc;
}


void count_file(char *filename) {
  long sloc;
  FILE *stream;
  stream = fopen(filename, "r");
  line_number = 1;
  sloc = sloc_count(filename, stream);
  total_sloc += sloc;
  printf("%ld\n", sloc);
  fclose(stream);
}

char *read_a_line(FILE *file) {
 char buffer[10000];
 char *returnval;
 char *newlinepos;
 returnval = fgets(buffer, sizeof(buffer), file);
 if (returnval) {
   newlinepos = buffer + strlen(buffer) - 1;
   if (*newlinepos == '\n') {*newlinepos = '\0';};
   return strdup(buffer);
 } else {
   return NULL;
 }
}

int main(int argc, char *argv[]) {
 long sloc;
 int i;
 FILE *file_list;
 char *s;

 total_sloc = 0;
 line_number = 1;

 if (argc <= 1) {
   sloc = sloc_count("-", stdin);
   printf("%ld %s\n", sloc, "-");
   total_sloc += sloc;
 } else if ((argc == 3) && (!strcmp(argv[1], "-f"))) {
   if (!strcmp (argv[2], "-")) {
     file_list = stdin;
   } else {
     file_list = fopen(argv[2], "r");
   }
   if (file_list) {
     while ((s = read_a_line(file_list))) {
       count_file(s);
       free(s);
     }
   }
 } else {
   for (i=1; i < argc; i++) { count_file(argv[i]); }
 }
 //printf("Total:\n");
// printf("%ld\n", total_sloc);
 return 0; /* Report success */
}