#include<stdio.h>

int main()
{
    int count=0;
    int ch;
    FILE *fptr;
    fptr=fopen("/home/Rahul/Desktop/Thesis/Scripts/Sample/Sample1.c","r");
    if(fptr == NULL)
    {
        perror("Error:");
    }
    else
    {
        do
        {
            ch=fgetc(fptr);
            if(ch == '\n')
                count++;
            if(ch == '//')
                count--;
            // code for removing BLANK lines
       /*     if(ch=='\*')
            {
                while(ch != '*\\')
                {
                    ch=fgetc(fptr);
                }
            }*/
        }while(ch != EOF);
    	  printf("the lines in the code are %d\n",count);
    	  fclose (fptr);
    }
 //   getchar();
    return 0;
}