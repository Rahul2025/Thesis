#include<stdio.h>
#include<string.h>
 
int main()
{  
   int t,i,j1,s1,k,count;
   char s[1001],j[1001];
   scanf("%d",&t);
   while(t--)
   {         count=0;
             scanf("%s",j);
             scanf("%s",s);
             for(i=0;i<strlen(s);i++)
             for(k=0;k<strlen(j);k++)
                             
                             if(s[i]==j[k])
                             {count++;
                            
                              break;}
                              
                              
                            printf("%d\n",count);
                            
                            }
                       
                            return 0;
                            
}