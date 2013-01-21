#include<stdio.h>
#include<math.h>
int main(int argc,char *argv[])
{
    int t;
    scanf("%d",&t);
    while(t--){
    int n,r=0,d=0,i,p;
    int s=0;
    scanf("%d",&n);
    while(n)
    {
        p=-1;
    for(i=0;i<12;i++)
    {
        s=(int) pow(2.0,i);
    if(n>=s)
    {    p++;
        
    }
    else if(n<s)
        break;
    }
    r++;
    s=(int) pow(2.0,p);
    if(p!=11)
    {
    n=n%s;
    }
    else
        n=n-s;}
   printf("%d \n",r);
    }
return 0;
}