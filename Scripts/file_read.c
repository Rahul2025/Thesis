//filename :: prac.c

#include <stdio.h>
#include <stdlib.h>
/* pre defined*/

#define PROG 26
#define LANG 5
#define C 0
#define CPP 1
#define HASK 2
#define JAVA 3
#define PYTH 4


/*Globals*/
int mat[PROG][LANG];

int main()
{
	
	FILE *op1;
	int val,val1,total[LANG]={0,0,0,0,0};
	int i=0,j=0,end=0;
	op1 = fopen("/home/Rahul/Desktop/Thesis/Scripts/loc","r");
	if(op1 == NULL)
		printf("Error in opening file....");
	else
	{
		/*printf("OK");
		while(fscanf(op1,"%d %d",&val,&val1) != EOF)
		{
			printf("%d %d \n",val,val1);
		}*/
		for(i=0;;i++)
		{
		//printf(" %d",i);
		for(j=0;j<LANG;j++)
		{
			if(fscanf(op1,"%d %d",&val,&val1) != EOF)
			{			
				mat[i][j] = val;
				mat[i+1][j] = val1;
			}
			else 
			{
				end=1;
				break;
			}
			//printf(" %d %d",i,j);
		}	
		if(end)
			break;
		i++;
	}
	printf("\tC\tCPP\tHASKELL\tJAVA\tPYTHON\n");
		printf("\t-\t---\t------\t----\t------\n");
		for(i=0;i<2*PROG;i++)
		{	
			for(j=0;j<LANG;j++)
			{
				printf("\t%d",mat[i][j]);
				total[j] = total[j] + mat[i][j];
			}
			printf("\n");
		}
		printf("\t----\t----\t----\t----\t----\n");
		for(i=0;i<LANG;i++)	
			printf("\t%d",total[i]);
		printf("\n");	
	}
	return 0;
}