#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std;

long long int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}



int main()
{
    int ch;
    scanf("%d",&ch);
    while(ch--)
    {
        int num;
        char brr[300];
        scanf("%d%s",&num,brr);
        int len =strlen(brr);
        int i=0;
        long long int mid=0;
        if(num==0)
        {
            printf("%s\n",brr);
            continue;
        }

        while(i<len)
        {
            while(mid<1000000000&&i<len)
            {
                mid=mid*10+(brr[i]-'0');
                i++;
            }
            mid=mid%num;
        }

        mid=gcd(num,mid);
        printf("%lld\n",mid);
    }
    return 0;
}