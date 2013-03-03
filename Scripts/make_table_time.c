#include <stdio.h>
#include <stdlib.h>

/* pre defined*/
//#define ROWS 24
//#define COLS 2
#define LANG 6
#define PROG 100
#define C 0
#define CPP 1
#define HASK 2
#define JAVA 3
#define PYTH 4
#define CYTH 5

/*Globals*/
//float mat[PROG][LANG];
float cmp_tim[PROG][LANG],cmp_mem[PROG][LANG],run_tim[PROG][LANG],run_mem[PROG][LANG];
float mod_cmp_tim[PROG][LANG],mod_cmp_mem[PROG][LANG],mod_run_tim[PROG][LANG],mod_run_mem[PROG][LANG];
float pen_mod_cmp_tim[PROG][LANG],pen_mod_cmp_mem[PROG][LANG],pen_mod_run_tim[PROG][LANG],pen_mod_run_mem[PROG][LANG];

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

/*Function to read input from txt file and store the results in a cmp_timrix*/
int make_cmp_tim(char *file,int j)
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
			//val = cmp_tim;
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
	FILE *op;
	int i,j,prog0,prog1,prog2,prog3,prog4,prog5;
	float tot_cmp_tim[LANG]={0,0,0,0,0,0},ratio_cmp_tim[LANG],mod_tot_cmp_tim[LANG]={0,0,0,0,0,0},pen_mod_tot_cmp_tim[LANG]={0,0,0,0,0,0};
	float tot_cmp_mem[LANG]={0,0,0,0,0,0},ratio_cmp_mem[LANG],mod_tot_cmp_mem[LANG]={0,0,0,0,0,0},pen_mod_tot_cmp_mem[LANG]={0,0,0,0,0,0};
	float tot_run_tim[LANG]={0,0,0,0,0,0},ratio_run_tim[LANG],mod_tot_run_tim[LANG]={0,0,0,0,0,0},pen_mod_tot_run_tim[LANG]={0,0,0,0,0,0};
	float tot_run_mem[LANG]={0,0,0,0,0,0},ratio_run_mem[LANG],mod_tot_run_mem[LANG]={0,0,0,0,0,0},pen_mod_tot_run_mem[LANG]={0,0,0,0,0,0};
	
	prog0=make_cmp_tim("c_time",C);
	prog1=make_cmp_tim("cpp_time",CPP);
	prog2=make_cmp_tim("hs_time",HASK);
	prog3=make_cmp_tim("java_time",JAVA);
	prog4=make_cmp_tim("pyth_time",PYTH);
	prog5=make_cmp_tim("cyth_time",CYTH);	
	
	
	if(prog0 && prog1 && prog2 && prog3 && prog4 && prog5)
	{	
		op = fopen("/home/Rahul/Desktop/Thesis/Scripts/final_data","a");
		fprintf(op,"\n\n");
		printf("\n\n\tC\t\tCPP\t\tHASKELL\t\tJAVA\t\tPYTHON\n");
		printf("\t-\t\t---\t\t-------\t\t----\t\t------");
		for(i=0;i<prog0;i++)
		{
			printf("\n");
        	for(j=0;j<LANG;j++)
         {
         	   printf("\t%f",cmp_tim[i][j]);
         	   tot_cmp_tim[j] = tot_cmp_tim[j] + cmp_tim[i][j];
         }
      }
      printf("\n\t----\t\t----\t\t----\t\t----\n");
		for(i=0;i<LANG;i++)	
		{
			ratio_cmp_tim[i] = tot_cmp_tim[0];
			printf("\t%f",tot_cmp_tim[i]);
		}
		for(i=0;i<prog0;i++)
			for(j=0;j<LANG-2;j++)
				if(cmp_tim[i][j] == 0)
					ratio_cmp_tim[j] = ratio_cmp_tim[j] - cmp_tim[i][C];
		printf("\n");	
		printf("\t----\t\t----\t\t----\t\t----\n");
		for(i=0;i<LANG-2;i++)	
		{
			ratio_cmp_tim[i] = tot_cmp_tim[i]/ratio_cmp_tim[i];
			printf("\t%f",ratio_cmp_tim[i]);
		}	
		printf("\n");
		printf("\t-\t\t---\t\t------\t\t------\n");
		for(i=0;i<prog0;i++)
		{
			for(j=0;j<LANG-2;j++)
			{
				if(cmp_tim[i][j] == 0)
				{
					if(cmp_tim[i][C] != 0)
						mod_cmp_tim[i][j] = ratio_cmp_tim[j]*cmp_tim[i][C];
					else if (cmp_tim[i][CPP] != 0)
						mod_cmp_tim[i][j] = (ratio_cmp_tim[j]/ratio_cmp_tim[CPP])*cmp_tim[i][CPP];
					else if (cmp_tim[i][JAVA] != 0)
						mod_cmp_tim[i][j] = (ratio_cmp_tim[j]/ratio_cmp_tim[JAVA])*cmp_tim[i][JAVA];
					else
						mod_cmp_tim[i][j] = (ratio_cmp_tim[j]/ratio_cmp_tim[HASK])*cmp_tim[i][HASK];
				//	if(j==C) || (j==CPP)
					pen_mod_cmp_tim[i][j] = penalty(mod_cmp_tim[i][j],j);
				}
				else
					pen_mod_cmp_tim[i][j] = mod_cmp_tim[i][j] = cmp_tim[i][j];							
			}
		}
		printf("\tC\t\tCPP\t\tHASKELL\t\tJAVA\t\tPYTHON\n");
		printf("\t-\t\t---\t\t-------\t\t----\t\t------\n");
		for(i=0;i<prog0;i++)
		{	
			for(j=0;j<LANG-2;j++)
			{
				if(cmp_tim[i][j])
					printf("\t%f",mod_cmp_tim[i][j]);
				
				else
					printf("\t%.5f*",mod_cmp_tim[i][j]);
				mod_tot_cmp_tim[j] = mod_tot_cmp_tim[j] + mod_cmp_tim[i][j];
			}
			printf("\n");
		}
		
		printf("\t----\t\t----\t\t----\t\t----\n");
	//	printf("\t-\t\t---\t\t-------\t\t----\t\t------\n");
		for(i=0;i<LANG-2;i++)	
		{
			//ratio[i] = total[0];
			printf("\t%f",mod_tot_cmp_tim[i]);
		}		
		printf("\n");
		printf("\t-\t\t---\t\t-------\t\t----\t\t------\n");
		for(i=0;i<prog0;i++)
		{	
			for(j=0;j<LANG-2;j++)
			{
				if(cmp_tim[i][j])
					printf("\t%f",pen_mod_cmp_tim[i][j]);
				
				else
					printf("\t%.5f**",pen_mod_cmp_tim[i][j]);
				pen_mod_tot_cmp_tim[j] = pen_mod_tot_cmp_tim[j] + pen_mod_cmp_tim[i][j];
			}
			printf("\n");
		}
		
		printf("\t----\t\t----\t\t----\t\t----\n");
		//printf("\t-\t\t---\t\t-------\t\t----\t\t------\n");
		for(i=0;i<LANG-2;i++)	
		{
			//ratio[i] = total[0];
			printf("\t%f",pen_mod_tot_cmp_tim[i]);
			fprintf(op,"\n\t%f",pen_mod_tot_cmp_tim[i]);
		}		
		printf("\n");
		
		
	printf("\n\n\tC\t\tCPP\t\tHASKELL\t\tJAVA\t\tPYTHON\n");
		printf("\t-\t\t---\t\t-------\t\t----\t\t------\n");
		for(i=0;i<prog0;i++)
		{
			printf("\n");
        	for(j=0;j<LANG;j++)
         {
         	   printf("\t%f",cmp_mem[i][j]);
         	   tot_cmp_mem[j] = tot_cmp_mem[j] + cmp_mem[i][j];
         }
      }
      printf("\n\t-\t\t---\t\t-------\t\t----\t\t------\n");
		for(i=0;i<LANG;i++)	
		{
			ratio_cmp_mem[i] = tot_cmp_mem[0];
			printf("\t%f",tot_cmp_mem[i]);
		}
		for(i=0;i<prog0;i++)
			for(j=0;j<LANG-2;j++)
				if(cmp_mem[i][j] == 0)
					ratio_cmp_mem[j] = ratio_cmp_mem[j] - cmp_mem[i][C];
		printf("\n");	
		printf("\t----\t\t----\t\t----\t\t----\n");
		for(i=0;i<LANG-2;i++)	
		{
			ratio_cmp_mem[i] = tot_cmp_mem[i]/ratio_cmp_mem[i];
			printf("\t%f",ratio_cmp_mem[i]);
		}	
		printf("\n");
		printf("\t-\t\t---\t\t-------\t\t----\t\t------\n");
		for(i=0;i<prog0;i++)
		{
			for(j=0;j<LANG-2;j++)
			{
				if(cmp_mem[i][j] == 0)
				{
					if(cmp_mem[i][C] != 0)
						mod_cmp_mem[i][j] = ratio_cmp_mem[j]*cmp_mem[i][C];
					else if (cmp_mem[i][CPP] != 0)
						mod_cmp_mem[i][j] = (ratio_cmp_mem[j]/ratio_cmp_mem[CPP])*cmp_mem[i][CPP];
					else if (cmp_mem[i][JAVA] != 0)
						mod_cmp_mem[i][j] = (ratio_cmp_mem[j]/ratio_cmp_mem[JAVA])*cmp_mem[i][JAVA];
					else
						mod_cmp_mem[i][j] = (ratio_cmp_mem[j]/ratio_cmp_mem[HASK])*cmp_mem[i][HASK];
				//	if(j==C) || (j==CPP)
					pen_mod_cmp_mem[i][j] = penalty(mod_cmp_mem[i][j],j);
				}
				else
					pen_mod_cmp_mem[i][j] = mod_cmp_mem[i][j] = cmp_mem[i][j];							
			}
		}
		printf("\tC\t\tCPP\t\tHASKELL\t\tJAVA\t\tPYTHON\n");
		printf("\t-\t\t---\t\t-------\t\t----\t\t------\n");
		for(i=0;i<prog0;i++)
		{	
			for(j=0;j<LANG-2;j++)
			{
				if(cmp_mem[i][j])
					printf("\t%f",mod_cmp_mem[i][j]);
				
				else
					printf("\t%.5f*",mod_cmp_mem[i][j]);
				mod_tot_cmp_mem[j] = mod_tot_cmp_mem[j] + mod_cmp_mem[i][j];
			}
			printf("\n");
		}
		
		printf("\t----\t\t----\t\t----\t\t----\n");
		for(i=0;i<LANG-2;i++)	
		{
			//ratio[i] = total[0];
			printf("\t%f",mod_tot_cmp_mem[i]);
		}		
		printf("\n");
		printf("\t-\t\t---\t\t-------\t\t----\t\t------\n");
		for(i=0;i<prog0;i++)
		{	
			for(j=0;j<LANG-2;j++)
			{
				if(cmp_mem[i][j])
					printf("\t%f",pen_mod_cmp_mem[i][j]);
				
				else
					printf("\t%.5f**",pen_mod_cmp_mem[i][j]);
				pen_mod_tot_cmp_mem[j] = pen_mod_tot_cmp_mem[j] + pen_mod_cmp_mem[i][j];
			}
			printf("\n");
		}
		
		printf("\t----\t\t----\t\t----\t\t----\n");
		for(i=0;i<LANG-2;i++)	
		{
			//ratio[i] = total[0];
			printf("\t%f",pen_mod_tot_cmp_mem[i]);
			fprintf(op,"\n\t%f",pen_mod_tot_cmp_mem[i]);
		}		
		printf("\n");


		
	printf("\n\n\tC\t\tCPP\t\tJAVA\t\tPYTHON\n");
		printf("\t-\t\t---\t\t----\t\t------");
		for(i=0;i<prog0;i++)
		{
			printf("\n");
        	for(j=0;j<LANG;j++)
         {
         	   printf("\t%f",run_tim[i][j]);
         	   tot_run_tim[j] = tot_run_tim[j] + run_tim[i][j];
         }
      }
      printf("\n\t----\t\t----\t\t----\t\t----\n");
		for(i=0;i<LANG;i++)	
		{
			ratio_run_tim[i] = tot_run_tim[0];
			printf("\t%f",tot_run_tim[i]);
		}
		for(i=0;i<prog0;i++)
			for(j=0;j<LANG;j++)
				if(run_tim[i][j] == 0)
					ratio_run_tim[j] = ratio_run_tim[j] - run_tim[i][C];
		printf("\n");	
		printf("\t----\t\t----\t\t----\t\t----\n");
		for(i=0;i<LANG;i++)	
		{
			ratio_run_tim[i] = tot_run_tim[i]/ratio_run_tim[i];
			printf("\t%f",ratio_run_tim[i]);
		}	
		printf("\n");
		printf("\t-\t\t---\t\t------\t\t------\n");
		for(i=0;i<prog0;i++)
		{
			for(j=0;j<LANG;j++)
			{
				if(run_tim[i][j] == 0)
				{
					if (run_tim[i][C] != 0)
						mod_run_tim[i][j] = ratio_run_tim[j]*run_tim[i][C];
					else if (run_tim[i][CPP] != 0)
						mod_run_tim[i][j] = (ratio_run_tim[j]/ratio_run_tim[CPP])*run_tim[i][CPP];
					else if (run_tim[i][JAVA] != 0)
						mod_run_tim[i][j] = (ratio_run_tim[j]/ratio_run_tim[JAVA])*run_tim[i][JAVA];
					else if (run_tim[i][PYTH] != 0)
						mod_run_tim[i][j] = (ratio_run_tim[j]/ratio_run_tim[PYTH])*run_tim[i][PYTH];
					else
						mod_run_tim[i][j] = (ratio_run_tim[j]/ratio_run_tim[HASK])*run_tim[i][HASK];
				//	if(j==C) || (j==CPP)
					pen_mod_run_tim[i][j] = penalty(mod_run_tim[i][j],j);
				}
				else
					pen_mod_run_tim[i][j] = mod_run_tim[i][j] = run_tim[i][j];							
			}
		}
		printf("\tC\t\tCPP\t\tHASKELL\t\tJAVA\t\tPYTHON\n");
		printf("\t-\t\t---\t\t-------\t\t----\t\t------\n");
		for(i=0;i<prog0;i++)
		{	
			for(j=0;j<LANG;j++)
			{
				if(run_tim[i][j])
					printf("\t%f",mod_run_tim[i][j]);
				
				else
					printf("\t%.5f*",mod_run_tim[i][j]);
				mod_tot_run_tim[j] = mod_tot_run_tim[j] + mod_run_tim[i][j];
			}
			printf("\n");
		}
		
		printf("\t----\t\t----\t\t----\t\t----\n");
		for(i=0;i<LANG;i++)	
		{
			//ratio[i] = total[0];
			printf("\t%f",mod_tot_run_tim[i]);
		}		
		printf("\n");
		printf("\t-\t\t---\t\t-------\t\t----\t\t------\n");
		for(i=0;i<prog0;i++)
		{	
			for(j=0;j<LANG;j++)
			{
				if(run_mem[i][j])
					printf("\t%f",pen_mod_run_tim[i][j]);
				
				else
					printf("\t%.5f**",pen_mod_run_tim[i][j]);
				pen_mod_tot_run_tim[j] = pen_mod_tot_run_tim[j] + pen_mod_run_tim[i][j];
			}
			printf("\n");
		}
		
		printf("\t----\t\t----\t\t----\t\t----\n");
		for(i=0;i<LANG;i++)	
		{
			//ratio[i] = total[0];
			printf("\t%f",pen_mod_tot_run_tim[i]);
			fprintf(op,"\n\t%f",pen_mod_tot_run_tim[i]);
		}		
		printf("\n");	
		
		
	printf("\n\n\tC\t\tCPP\t\tHASKELL\t\tJAVA\t\tPYTHON\n");
		printf("\t-\t\t---\t\t----\t\t------");
		for(i=0;i<prog0;i++)
		{
			printf("\n");
        	for(j=0;j<LANG;j++)
         {
         	   printf("\t%f",run_mem[i][j]);
         	   tot_run_mem[j] = tot_run_mem[j] + run_mem[i][j];
         }
      }
      printf("\n\t----\t\t----\t\t----\t\t----\n");
		for(i=0;i<LANG;i++)	
		{
			ratio_run_mem[i] = tot_run_mem[0];
			printf("\t%f",tot_run_mem[i]);
		}
		for(i=0;i<prog0;i++)
			for(j=0;j<LANG;j++)
				if(run_mem[i][j] == 0)
					ratio_run_mem[j] = ratio_run_mem[j] - run_mem[i][C];
		printf("\n");	
		printf("\t----\t\t----\t\t----\t\t----\n");
		for(i=0;i<LANG;i++)	
		{
			ratio_run_mem[i] = tot_run_mem[i]/ratio_run_mem[i];
			printf("\t%f",ratio_run_mem[i]);
		}	
		printf("\n");
		printf("\t-\t\t---\t\t------\t\t------\n");
		for(i=0;i<prog0;i++)
		{
			for(j=0;j<LANG;j++)
			{
				if(run_mem[i][j] == 0)
				{
					if(run_mem[i][C] != 0)
						mod_run_mem[i][j] = ratio_run_mem[j]*run_mem[i][C];
					else if (run_mem[i][CPP] != 0)
						mod_run_mem[i][j] = (ratio_run_mem[j]/ratio_run_mem[CPP])*run_mem[i][CPP];
					else if (run_mem[i][JAVA] != 0)
						mod_run_mem[i][j] = (ratio_run_mem[j]/ratio_run_mem[JAVA])*run_mem[i][JAVA];
					else if (run_mem[i][PYTH] != 0)
						mod_run_mem[i][j] = (ratio_run_mem[j]/ratio_run_mem[PYTH])*run_mem[i][PYTH];
					else
						mod_run_mem[i][j] = (ratio_run_mem[j]/ratio_run_mem[HASK])*run_mem[i][HASK];
				//	if(j==C) || (j==CPP)
					pen_mod_run_mem[i][j] = penalty(mod_run_mem[i][j],j);
				}
				else
					pen_mod_run_mem[i][j] = mod_run_mem[i][j] = run_mem[i][j];							
			}
		}
		printf("\tC\t\tCPP\t\tHASKELL\t\tJAVA\t\tPYTHON\n");
		printf("\t-\t\t---\t\t-------\t\t----\t\t------\n");
		for(i=0;i<prog0;i++)
		{	
			for(j=0;j<LANG;j++)
			{
				if(run_mem[i][j])
					printf("\t%f",mod_run_mem[i][j]);
				
				else
					printf("\t%.5f*",mod_run_mem[i][j]);
				mod_tot_run_mem[j] = mod_tot_run_mem[j] + mod_run_mem[i][j];
			}
			printf("\n");
		}
		
		printf("\t----\t\t----\t\t----\t\t----\n");
		for(i=0;i<LANG;i++)	
		{
			//ratio[i] = total[0];
			printf("\t%f",mod_tot_run_mem[i]);
		}		
		printf("\n");
		printf("\t-\t\t---\t\t-------\t\t----\t\t------\n");
		for(i=0;i<prog0;i++)
		{	
			for(j=0;j<LANG;j++)
			{
				if(run_mem[i][j])
					printf("\t%f",pen_mod_run_mem[i][j]);
				
				else
					printf("\t%.5f**",pen_mod_run_mem[i][j]);
				pen_mod_tot_run_mem[j] = pen_mod_tot_run_mem[j] + pen_mod_run_mem[i][j];
			}
			printf("\n");
		}
		
		printf("\t----\t\t----\t\t----\t\t----\n");
		for(i=0;i<LANG;i++)	
		{
			//ratio[i] = total[0];
			printf("\t%f",pen_mod_tot_run_mem[i]);
						fprintf(op,"\n\t%f",pen_mod_tot_run_mem[i]);
		}		
		printf("\n");
 /*     printf("\n\n\tC\t\tCPP\t\tJAVA\t\tPYTHON\n");
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
      }*/	
      printf("\n");
      fclose(op);
	}	
	else 
		printf("failed to open file...\n");
	return 1;
}