#include<stdio.h>

int main()
{
    long int a,b;
    
    while(scanf("%ld %ld",&a,&b)==2)
    {
        if((a-b)%10!=9)
        printf("%ld\n",a-b+1);
        else
        printf("%ld\n",a-b-1);

    }
    return 0;
}