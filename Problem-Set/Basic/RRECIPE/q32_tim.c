#include<stdio.h>
#include<string.h>
# define MOD 10000009
int main()
{
    int l,t,i,res;
    char str[1000005];
    scanf("%d\n",&t);
    while(t--)
    {
        gets(str);
        l=strlen(str);
        res=1;
        for(i=0;i<(l+1)/2;i++)
        {
            if(str[i]==str[l-1-i])
            {
                if(str[i]=='?')
                res=(res*26)%MOD;
                
            }
            else
            {
                if(str[i]!='?'&&str[l-1-i]!='?')
                {
                    res=0;
                break;
                }
                
            }
        }
        printf("%d\n",res);
    }
} 