#include<stdio.h>
int testfloat(float x);
int a[5],flag=0;
float price,n;
int z;
int t,i,j;
int main()
{
    
    scanf("%d",&t);
while(t--)
{     flag=0;
     scanf("%f",&n);
     scanf("%d%d%d",&a[1],&a[2],&a[3]);
     for(i=9;i>=1;i--)
     {
         for(j=9;j>=0;j--)
             {
     a[0]=i;
     a[4]=j;
     price=(a[0]*10000)+(a[1]*1000)+(a[2]*100)+(a[3]*10)+a[4];
     
     if(!testfloat(price/n))
     {
   z=price/n;
    printf("%d %d %d\n",i,j,z);
    flag=1;
    break;
     }
              }
     if(flag==1)
     break;
     }
     if(flag==0)
     printf("0\n");
}
              
              
    return 0;
}



     
int testfloat(float x)
{
    int y;
    y=(x*10)/10;
    if(y==x)
    return 0;
    else return 1;
}