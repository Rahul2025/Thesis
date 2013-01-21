#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char format[100][20],full[100][60],file[100][100];
int main()
{
      int n,q,i,flag,j,k;
      scanf("%d %d",&n,&q);
      for(i=0;i<n;i++)
      {
                scanf("\n%s %s",format[i],full[i]);
      }
      while(q>0)
      {
                flag=0;
                scanf("\n%s",file[q]);
                for(j=strlen(file[q])-1;j>=0;j--)
                {
                       if(file[q][j]=='.')
                       {
                                flag=1;       
				break;
                       }
                }
                j++;
		if(flag==1)
		{
                for(i=0;i<n;i++)
                {
                                if(strcmp(&file[q][j],format[i])==0)
                                {
                                           printf("\n%s",full[i]);
                                           flag=1;
                                           break;
                                }
                                else
                                {
                                     flag=0;
                                }
                }
		}
                if(flag==0)
                {
                            printf("\nunknown");
                }
                q--;
      }
      return 0;  
}