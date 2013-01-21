#include <stdio.h>
#include <stdlib.h>

/* pre defined*/
#define ROWS 24
#define COLS 2
#define LANG 4
#define PROG 4
#define C 0
#define CPP 1
#define JAVA 2
#define PYTH 3

/*Globals*/
float mat[ROWS][COLS];
float cmp_tim[PROG][LANG],cmp_mem[PROG][LANG],run_tim[PROG][LANG],run_mem[PROG][LANG];

/*Function to read input from txt file and store the results in a matrix*/
int make_mat()
{
	FILE *op1;
	float val;
	int i,j;
	op1 = fopen("/home/Rahul/Desktop/Thesis/Scripts/op","r");
	if(op1 == NULL)
		return 0;
		
	for(i=0;i<ROWS;i++)
	{
		for(j=0;j<COLS;j++)
		{
			fscanf(op1,"%f",&val);
//			printf(" %f ",val);
			mat[i][j] = val;
		}
//		printf("\n");
	}
	fclose(op1);
	return 1;
}

/**/
int make_table()
{
	int p=0;
	
	float *val;
	val = &mat[0];
	if(make_mat())
	{
	/*	for(i=0;i<ROWS;i++)
			for(j=0;j<COLS;j++)
				printf(" %f ",mat[i][j]); */
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

int main()
{
	int i,j;
	if(make_table())
	{		
		for(i=0;i<PROG;i++)
		{
			printf("\n");
        	for(j=0;j<LANG;j++)
            printf(" %f ",cmp_tim[i][j]);
      }
      printf("\n");
      for(i=0;i<PROG;i++)
		{
			printf("\n");
        	for(j=0;j<LANG;j++)
            printf(" %f ",cmp_mem[i][j]);
      }
		printf("\n");
		for(i=0;i<PROG;i++)
		{
			printf("\n");
        	for(j=0;j<LANG;j++)
            printf(" %f ",run_tim[i][j]);
      }
      printf("\n");
		for(i=0;i<PROG;i++)
		{
			printf("\n");
     	   for(j=0;j<LANG;j++)
            printf(" %f ",run_mem[i][j]);
      }	
      printf("\n");
	}	
	else 
		printf("failed to open file...\n");
	return 1;
}