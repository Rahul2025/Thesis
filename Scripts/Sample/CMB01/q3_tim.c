#include<stdio.h>
int reverse(int n)
{
     int temp=0,rev=0;
     
     while(n>0)
     {temp=n%10;
     
                rev=rev*10+temp;
                //temp=n%10;
                n=n/10;
                }
                return rev;
                }
     
int main()
{
    int t,m,n,sum=0;
    scanf("%d",&t);
    while(t--)
    {
              scanf("%d%d",&m,&n);
              m=reverse(m);
              n=reverse(n);
              sum=m+n;
              printf("%d\n",reverse(sum));
              }
              return 0;
    }