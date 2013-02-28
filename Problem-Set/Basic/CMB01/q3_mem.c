#include<stdio.h>

int main()
{
    long int n1,n2,num1,num2,num3;
    int t;
    
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%ld %ld",&n1,&n2);
        
        num1=0;
        num2=0;
        num3=0;
        
        while(n1)
        {
            num1=num1*10+(n1%10);
            n1/=10;
        }
        
        while(n2)
        {
            num2=num2*10+(n2%10);
            n2/=10;
        }
        
        n1=num1+num2;
        
        num1=0;
        
        while(n1)
        {
            num3=num3*10+(n1%10);
            n1/=10;
        }
        
        printf("%ld\n",num3);
    }
    return 0;
}