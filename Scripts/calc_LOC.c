#include <stdio.h>
#include <stdlib.h>

/* pre defined*/

#define PROG 30
#define LANG 4
#define C 0
#define CPP 1
#define JAVA 2
#define PYTH 3
#define HASK 4

/*Globals*/
int mat[PROG][4];

/*Function to read input from txt file and store the results in a matrix*/
int make_mat()
{
	FILE *op1;
	int val;
	int i,j;
	op1 = fopen("/home/Rahul/Desktop/Thesis/Scripts/loc","r");
	if(op1 == NULL)
		return 0;
		
	for(i=0;i<PROG;i++)
	{
			fscanf(op1,"%d",&val);
			mat[i][C] = val;	
	//printf(" %d ",mat[i][0]);
	}
	for(i=0;i<PROG;i++)
	{
			fscanf(op1,"%d",&val);
			mat[i][CPP] = val;
	//printf(" %d ",mat[i][1]);
	}
	for(i=0;i<PROG;i++)
	{
			fscanf(op1,"%d",&val);	
			mat[i][JAVA] = val;
			//printf(" %d ",mat[i][2]);
	}
	for(i=0;i<PROG;i++)
	{
			fscanf(op1,"%d",&val);			
			mat[i][PYTH] = val;
			//printf(" %d ",mat[i][3]);
	}
	fclose(op1);
	return 1;
}

int main()
{
	int i,j,total[LANG]={0,0,0,0};
	if(make_mat())
	{		
		printf("\tC\tCPP\tJAVA\tPYTHON\n");
		printf("\t-\t---\t----\t------\n");
		for(i=0;i<PROG;i++)
		{	
			for(j=0;j<LANG;j++)
			{
				printf("\t%d",mat[i][j]);
				total[j] = total[j] + mat[i][j];
			}
			printf("\n");
		}
		printf("\t----\t----\t----\t----\n");
		for(i=0;i<LANG;i++)	
			printf("\t%d",total[i]);
		printf("\n");		
	}
	else 
		printf("failed to open file...\n");
	return 1;
}