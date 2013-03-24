#include<stdio.h>

int make(char *argv)
{
	FILE *op;
	op = fopen("run.py","w+");
	if(op == NULL)
		return 0;
	fprintf(op,"%s","# filename : run.py\n\n");
	fprintf(op,"%s","import time\n");
	fprintf(op,"%s","f = open('/home/Rahul/Desktop/Thesis/Scripts/cyth_time', 'a')\n");
	fprintf(op,"%s","start = time.time()\n");
	fprintf(op,"%s","import ");
	fprintf(op,"%s",argv);
	fprintf(op,"%s","\nf.write(str(time.time() - start))\n");
	fprintf(op,"%s","f.write(' ')\n");
	fprintf(op,"%s","f.close");
	fclose(op);
	return 1;
}

int main(int argc, char *argv[])
{
	int prog;
	prog=make(argv[1]);
	if (prog)
		printf("Successfully run\n\n");
	else 
		printf("Not Successfull\n");
	return 0;
}