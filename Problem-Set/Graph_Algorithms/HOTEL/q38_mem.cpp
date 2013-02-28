#include<stdio.h>
//#include<conio.h>

int main()
{
    int t=0;
    int a[1000],d[1000],ar[1000],de[1000];
    int n=0,x=0;
    int c=0,i=0,max=-1;
    
    scanf("%d",&t);
    
    for(i=0;i<=1000;i++)
    {
               a[i]=0;        
               d[i]=0;
    }
    
    while(t--)
    {
           scanf("%d",&n);
           for(i=0;i<n;i++)
           {
                       scanf("%d",&x);                           
                       a[x]++;
           }
           for(i=0;i<n;i++)
           {
                           scanf("%d",&x);
                           d[x]++;
           }
           
           for(i=1;i<1000;i++)
           {
                           if(a[i]!=0)
                           {
                                      c+=a[i];
                                      a[i]=0;
                                      
                           }
                           if(d[i]!=0)
                           {
                                      c-=d[i];
                                      d[i]=0;
                                      //if(max<c)
                                     // max=c;
                           }
                        //   printf("c is: %d",c);
                                     if(max<c)
                                      max=c;
           }
           
           printf("%d\n",max);
           c=0;
           max=-1;
    }
    
    return 0;
}