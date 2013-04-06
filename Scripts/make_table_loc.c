#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/* pre defined*/

#define PROG 75
#define LANG 5
#define C 0
#define CPP 1
#define HASK 2
#define JAVA 3
#define PYTH 4
#define CYTH 5


/*Globals*/
int mat[PROG][LANG];
float mod_mat[PROG][LANG];
float pen_mod_mat[PROG][LANG];

/*Function to apply PENALTY if code is not there in language 'j'*/
float penalty(float val,int lang)
{
	float final_val;
	if(lang == 0)
		final_val = val*1.20;
	else if(lang == 1)
		final_val = val*1.19;
	else if(lang == 2)
		final_val = val*1.11;
	else if(lang == 3)
		final_val = val*1.16;
	else 
		final_val = val*1.14;
	return final_val;
}	

/*Function to read input from txt file and store the results in a matrix*/
int make_mat(char *argv)
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
	}*/
	fclose(op1);
	return i--;
}

/*Main Function*/
int main(int argc, char *argv[])
{
	FILE *op;
	int i,j,prog,total[LANG]={0,0,0,0,0};
	float ratio[LANG],mod_total[LANG]={0,0,0,0,0},pen_mod_total[LANG]={0,0,0,0,0};
	//char filename[100]="";
	//scanf("%s",filename);
	prog=make_mat(argv[1]);
	op = fopen("/home/Rahul/Desktop/Thesis/Scripts/final_loc.csv","a");
	if(prog)
	{		
		//printf("\tC\t\tCPP\t\tHASKELL\t\tJAVA\t\tPYTHON\n");
		//printf("\t-\t\t---\t\t------\t\t----\t\t------\n");
		for(i=0;i<prog;i++)
		{	
			for(j=0;j<LANG;j++)
			{
				printf("\t%d\t",mat[i][j]);
				total[j] = total[j] + mat[i][j];
			}
			printf("\n");
		}
		
		printf("\n\t----\t\t----\t\t----\t\t----\t\t----\n");
		for(i=0;i<LANG;i++)	
		{
			ratio[i] = total[0];
			printf("\t%d\t",total[i]);
		}		
		for(i=0;i<prog;i++)
			for(j=0;j<LANG;j++)
				if(mat[i][j] == 0)
					ratio[j] = ratio[j] - mat[i][C];
		printf("\n");	
		printf("\t----\t\t----\t\t----\t\t----\t\t----\n");
		for(i=0;i<LANG;i++)	
		{
			ratio[i] = total[i]/ratio[i];
			printf("\t%f",ratio[i]);
		}	
		printf("\n");
		printf("\t-\t\t---\t\t------\t\t----\t\t------\n");
		for(i=0;i<prog;i++)
		{
			for(j=0;j<LANG;j++)
			{
				if(mat[i][j] == 0)
				{
					if(mat[i][C] != 0)
						mod_mat[i][j] = ratio[j]*mat[i][C];
					else
						mod_mat[i][j] = (ratio[j]/ratio[CPP])*mat[i][CPP];
				//	if(j==C) || (j==CPP)
					pen_mod_mat[i][j] = penalty(mod_mat[i][j],j);
				}
				else
					pen_mod_mat[i][j] = mod_mat[i][j] = mat[i][j];							
			}
		}
		printf("\tC\t\tCPP\t\tHASKELL\t\tJAVA\t\tPYTHON\n");
		printf("\t-\t\t---\t\t------\t\t----\t\t------\n");
		for(i=0;i<prog;i++)
		{	
			for(j=0;j<LANG;j++)
			{
				if(mat[i][j])
					printf("\t%f",mod_mat[i][j]);
				
				else
					printf("\t%.5f*",mod_mat[i][j]);
				mod_total[j] = mod_total[j] + mod_mat[i][j];
			}
			printf("\n");
		}
		
		printf("\t----\t\t----\t\t----\t\t----\t\t----\n");
		for(i=0;i<LANG;i++)	
		{
			//ratio[i] = total[0];
			printf("\t%f",mod_total[i]);
		}		
		printf("\n");
		printf("\t-\t\t---\t\t------\t\t----\t\t------\n");
		for(i=0;i<prog;i++)
		{	
			for(j=0;j<LANG;j++)
			{
				if(mat[i][j])
					printf("\t%f",pen_mod_mat[i][j]);
				
				else
					printf("\t%.5f**",pen_mod_mat[i][j]);
				pen_mod_total[j] = pen_mod_total[j] + pen_mod_mat[i][j];
			}
			printf("\n");
		}
		
		printf("\t----\t\t----\t\t----\t\t----\t\t----\n");
//		fprintf(op,"c,cpp,haskell,java,python\n");
		for(i=0;i<LANG;i++)	
		{
			//ratio[i] = total[0];
			printf("\t%f",pen_mod_total[i]);
			if ( i == LANG-1 )
				fprintf(op,"%f,%f",pen_mod_total[i],pen_mod_total[i]);
			else 
				fprintf(op,"%f,",pen_mod_total[i]);
		}		
		fprintf(op,"\n");
		printf("\n");
		printf("---------------------------------------------------------------------------\n");
		fclose(op);
	}
	else 
		printf("\nfailed to open file...\n");
	return 1;
}