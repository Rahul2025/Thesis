#include<stdio.h>
//#include<stdlib.h>
void insertionsort(int *a,int n)
{
     int i,j,temp,key;
     for(i=1;i<n;i++)
     {
          key=a[i];
          for(j=i-1;j>=0;j--)
          {
                if(a[j]>key)
                    a[j+1]=a[j];
                else
                    break;
          }
          a[j+1]=key;
     }
}
int main()
{
    int i,j,t,x,n,p[30],r[30];
    scanf("%d",&t);
    while(t--)
    {
              scanf("%d",&n);
              for(i=0;i<n;i++)
                              scanf("%d",&p[i]);
              for(i=0;i<n;i++)
                              scanf("%d",&r[i]);
              insertionsort(p,n);
              insertionsort(r,n);
              x=0;
              j=0;
              for(i=0;i<n;i++)
              {
                       while(j<n)
                       {
                                 if(p[i]<=r[j])
                                 {
                                               x++;
                                               j++;
                                               break;
                                 }
                                 j++;
                       }
                       if(j==n)
                       break;
              }
              printf("%d\n",x);
    } 
    return 0;
}