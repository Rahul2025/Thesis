#include<stdio.h>
#include<string.h>
#include<iostream.h>
using namespace std;

int main()
{
     int t;
     scanf("%d",&t);
     while(t--)
     {
                int n,l,j,i,k,count,m=0;
                fflush(stdin);
                scanf("%d",&n);
                char a[200][30];
                char b[200][20];
                for(i=0;i<n;i++)
                {
                                fflush(stdin);
                                scanf("%s",&a[i]);
                                scanf("%s",&b[i]);
                                fflush(stdin);
                }
                for(i=0;i<n;i++)
                {
                
                 count=0;
                 for(j=i+1;j<n;j++)
                 {
                                   if(strcmp(a[i],a[j])==0)
                                                           count++;
                 }
                if(count==0){
                              if(b[i][0]=='+')
                              m++;
                              else if(b[i][0]=='-')
                              m--;
                              }
                              }           
                
                              printf("%d\n",m);
                              
                              }}