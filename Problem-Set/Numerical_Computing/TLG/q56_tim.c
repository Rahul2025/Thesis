#include<stdio.h>
int fastread()
{
int input;
char c=0;
while (c<33) c=getchar_unlocked();
input=0;
while (c>33)
{
input=input*10+c-'0';
c=getchar_unlocked();
}
return input;
}
int main()
{
   int n,a1,a2,max1=0,max2=0,t1=0,t2=0;
   n=fastread();
   while(n--)
   {
       a1=fastread();
       a2=fastread();
       t1+=a1;
       t2+=a2;
       //printf("%d %d\n",t1,t2);
       if(t1>t2)
       {
           if((t1-t2)>max1)
           {
            max1=t1-t2;
           }

       }
       else if(t1<t2)
       {
         if((t2-t1)>max2)
         {
             max2=t2-t1;
         }
       }

   }
    if(max1>max2)
    printf("1 %d",max1);
    else
    printf("2 %d",max2);
    return 0;
}
