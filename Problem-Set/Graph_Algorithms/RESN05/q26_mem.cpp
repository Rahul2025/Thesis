#include<iostream>
using namespace std;

int power(int b)
{
    int result=1;
    while(b--)
        result*=2;
    return result;
}

int main()
{
    int t,n,i;
    long long sum;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d",&n);
        if(n>23)
            n=23;
        for(i=1;i<=n;i++)
            sum+=(((i*(i+1))/2)*power(i-1));
        sum%=8388608;
        printf("%d\n",sum);
    }
    return 0;
}