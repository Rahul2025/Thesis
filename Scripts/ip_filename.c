//filename :: ip_filename.c

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*int main(int argc, char *argv[])
{
	//char filename[100]="";
	FILE *file;
	int val,val1;
//	printf("%d , %s",argc,argv[1]);
	file=fopen(argv[1],"r");
	if(file)
	{	
		fscanf(file,"%d %d",&val,&val1);
		printf("%d %d",val,val1);
	}
	
	else 
	{
		printf("File not found...");
	}
	return 0;
}
*/
int main()
{
	char s;
	FILE *file,*file1,*file2,*file3;
	int val0;
	float val,val1,val2,val3,val4;
//	printf("%d , %s",argc,argv[1]);
	file=fopen("/home/Rahul/Desktop/Thesis/Scripts/op_tim","r");
	file1=fopen("/home/Rahul/Desktop/Thesis/Scripts/op","w");
	if(file)
	{	
		while((s=fgetc(file)) != EOF)
		{
			if(s == '.')
				fprintf(file1,".");
			else if(s == 'm')
				fprintf(file1," ");
			else if(s == '\n')
				fprintf(file1,"\n");
			else if(!(isdigit(s)))
				fprintf(file1,"");	
			else
			{
				val0 = s - '0';
				fprintf(file1,"%d",val0);
				//printf("%d",val);
			}
		}
		fclose(file);
		fclose(file1);
		file=fopen("/home/Rahul/Desktop/Thesis/Scripts/op_tim","w");
		file1=fopen("/home/Rahul/Desktop/Thesis/Scripts/op","r");
		
		while((fscanf(file1,"%f %f %f %f",&val1,&val2,&val3,&val4)) != EOF)
		{
			val = (val1+val3)*60 + (val2+val4);
		//printf("%f",val);
			fprintf(file,"%f\n",val);
		}
	}
	else 
	{
		printf("File not found...");
	}
	return 0;
}