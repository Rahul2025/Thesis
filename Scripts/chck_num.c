#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/* pre defined*/

#define PROG 80
#define LANG 5
#define C 0
#define CPP 1
#define HASK 2
#define JAVA 3
#define PYTH 4


/*Globals*/
int mat[PROG][LANG];

/*Function to read input from txt file and store the results in a matrix*/
/*int make_mat(char *argv)
{
	FILE *op1;
	int val,val1,end=0;
	int i,j;
op1 = fopen(argv,"r");
	//op1 = fopen("/home/Rahul/Desktop/Thesis/Scripts/loc_graph","r");
//	op1 = stdin;
  // op1 = fopen(argv[2], "r");
	if(op1 == NULL)
		return 0;
		
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
	
	
	/*
	for(i=0;i<PROG;i++)
	{
			fscanf(op1,"%d",&val);
			mat[i][C] = val;	
	//printf(" %d ",mat[i][0]);
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
	return i--;
}
*/
int main(int argc, char *argv[])
{
	int i,j,prog=1,total[LANG]={0,0,0,0,0};
	//char filename[100]="";
	//scanf("%s",filename);
	FILE *op1;
	int val,val1,end=0;
	//int i,j;
	//op1 = fopen(argv[1],"r");
	//op1 = fopen("/home/Rahul/Desktop/Thesis/Scripts/loc","r");
//	op1 = stdin;
   op1 = fopen(argv[1], "r");
	if(op1 == NULL)
	{
		printf("failed to open file...\n");
		return 0;
	}
	
	else 
	{	
		for(i=0;;i++)
		{
		//printf("%d",i);
			for(j=0;j<LANG;j++)
			{
				if(fscanf(op1,"%d %d",&val,&val1) != EOF)
				{			
					mat[i][j] = val;
					mat[i+1][j] = val1;
					//printf("%d%d",mat[i][j],mat[i+1][j]);
				}
				else 
				{
					end=1;
					break;
				}
			
			}	
		if(end)
			break;
		i++;
		}
	}
		fclose(op1);
		prog = i-1;
		
	//printf("prog = %d",prog);
	//prog=make_mat(argv[1]);		
		printf("\n\tC\tCPP\tHASKELL\tJAVA\tPYTHON\n");
		printf("\t-\t---\t------\t----\t------\n");
		for(i=0;i<prog;i++)
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
	
		
	return 1;
}