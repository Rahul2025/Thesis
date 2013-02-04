#include <stdio.h>
#include <stdlib.h>

/* pre defined*/
//#define ROWS 24
//#define COLS 2
#define LANG 4
#define PROG 75
#define C 0
#define CPP 1
#define JAVA 2
#define PYTH 3

/*Globals*/
//float mat[PROG][LANG];
float cmp_tim[PROG][LANG],cmp_mem[PROG][LANG],run_tim[PROG][LANG],run_mem[PROG][LANG];

/*Function to read input from txt file and store the results in a matrix*/
int make_mat(char *file,int j)
{
	FILE *op1;
	float val0,val1,val2,val3;
	int i;
	//op1 = fopen("/home/Rahul/Desktop/Thesis/Scripts/c_time","r");
	op1 = fopen(file,"r");	
	if(op1 == NULL)
		return 0;
		
	//for(j=0;j<LANG;j++)
	
		for(i=0;;i++)
		{
			if(fscanf(op1,"%f %f %f %f",&val0,&val1,&val2,&val3) != EOF)
//			printf(" %f ",val);
			{
				cmp_tim[i][j] = val0;
				cmp_mem[i][j] = val1;
				run_tim[i][j] = val2;
				run_mem[i][j] = val3;
			}
			//printf("\n%f %f %f %f",val0,val1,val2,val3);}
			else 
				break;
		}
//		printf("\n");
	//}
	fclose(op1);
	return i--;
}

/*
int make_table()
{
	int p=0;
	
	float *val;
	val = &mat[0];
	if(make_mat())
	{
	/*	for(i=0;i<ROWS;i++)
			for(j=0;j<COLS;j++)
				printf(" %f ",mat[i][j]); 
		while(p<PROG)	
		{
			//val = mat;
			cmp_tim[p][C] = *val++;
			cmp_mem[p][C] = *val++;
			run_tim[p][C] = *val++;
			run_mem[p][C] = *val++;
			p++;
		}
		p=0;
		while(p<PROG)	
		{
			cmp_tim[p][CPP] = *val++;
			cmp_mem[p][CPP] = *val++;
			run_tim[p][CPP] = *val++;
			run_mem[p][CPP] = *val++;
			p++;
		}
		p=0;
		while(p<PROG)	
		{
			cmp_tim[p][JAVA] = *val++;
			cmp_mem[p][JAVA] = *val++;
			run_tim[p][JAVA] = *val++;
			run_mem[p][JAVA] = *val++;
			p++;
		}
		p=0;
		while(p<PROG)	
		{
			cmp_tim[p][PYTH] = 0;
			cmp_mem[p][PYTH] = 0;
			run_tim[p][PYTH] = *val++;
			run_mem[p][PYTH] = *val++;
			p++;
		}
	return 1;
	}
	else 
		return 0;
}
*/
int main()
{
	int i,j,prog0,prog1,prog2,prog3;
	prog0=make_mat("c_time",C);
	prog1=make_mat("cpp_time",CPP);
	prog2=make_mat("java_time",JAVA);
	prog3=make_mat("pyth_time",PYTH);
	
	if(prog0 && prog1 && prog2 && prog3)
	{	
	printf("\n\n\tC\t\tCPP\t\tJAVA\t\tPYTHON\n");
		printf("\t-\t\t---\t\t----\t\t------");
		for(i=0;i<prog0;i++)
		{
			printf("\n");
        	for(j=0;j<LANG;j++)
            printf("\t%f",cmp_tim[i][j]);
      }
      printf("\n\n\tC\t\tCPP\t\tJAVA\t\tPYTHON\n");
		printf("\t-\t\t---\t\t----\t\t------");
      for(i=0;i<prog0;i++)
		{
			printf("\n");
        	for(j=0;j<LANG;j++)
            printf("\t%f",cmp_mem[i][j]);
      }
		printf("\n\n\tC\t\tCPP\t\tJAVA\t\tPYTHON\n");
		printf("\t-\t\t---\t\t----\t\t------");
		for(i=0;i<prog0;i++)
		{
			printf("\n");
        	for(j=0;j<LANG;j++)
            printf("\t%f",run_tim[i][j]);
      }
     printf("\n\n\tC\t\tCPP\t\tJAVA\t\tPYTHON\n");
		printf("\t-\t\t---\t\t----\t\t------");
		for(i=0;i<prog0;i++)
		{
			printf("\n");
     	   for(j=0;j<LANG;j++)
            printf("\t%f",run_mem[i][j]);
      }	
      printf("\n");
	}	
	else 
		printf("failed to open file...\n");
	return 1;
}