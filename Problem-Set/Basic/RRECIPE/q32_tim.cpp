#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    long int i,l,n,m;
    char s[1000000];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(s);
        n=strlen(s);
        l=(n+1)/2;
        m=1;
        for(i=0;i<l;i++)
        {
            if((s[i]=='?')&&(s[n-i-1]=='?'))
            {
                    m=(m*26)%10000009;
            }
            else if((s[i]!=s[n-i-1])&&(s[n-i-1]!='?')&&(s[i]!='?'))
            {
                m=0;
                break;
            }
        }
        printf("%ld\n",m);
    }
    return 0;
}