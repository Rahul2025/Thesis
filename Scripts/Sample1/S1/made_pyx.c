#include<stdio.h>
int main()
{
	FILE *op,*op1;
	op = fopen("Sample1.py","r");
	op1 = fopen("Sample1.pyx","a");
	
	fprintf(op1,"import time");
	fprintf(op1,"start = (time.time()) * 1000000");
	do
   {
   	ch=fgetc(op);
   	fprintf(op1,ch);
   }while(ch != EOF);
	fprintf(op1,"end = (time.time()) * 1000000");
	fprintf(op1,"print end-start");
	
	
	)