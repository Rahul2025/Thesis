#include<stdio.h>
#include<string.h>
int main()
{
    char s[101],j[101];
    int n,q=0,t,i,k,a[26]={0},b[26]={0},c[26]={0},d[26]={0};
    scanf("%d",&t);
    scanf("%*c");
    while(t--)
    {
        q=0;
        for(i=0;i<26;i++)
        {
            a[i]=b[i]=c[i]=d[i]=0;
        }
        scanf("%s",&s);
        scanf("%*c");
        scanf("%s",&j);
        n=strlen(s);
        k=strlen(j);
        for(i=0;i<n;i++)
        {
            if(s[i]>=65 && s[i]<=90)
            {
                a[s[i]-65]++;
            }
            if(s[i]>=97 && s[i]<=122)
            {
                b[s[i]-97]++;
            }
        }
        for(i=0;i<k;i++)
        {
            if(j[i]>=65 && j[i]<=90)
            {
                c[j[i]-65]++;
            }
            if(j[i]>=97 && j[i]<=122)
            {
                d[j[i]-97]++;
            }
        }
        for(i=0;i<26;i++)
        {
            if(a[i]>0)
            q+=c[i];
            if(b[i]>0)
            q+=d[i];
        }
        printf("%d\n",q);
    }
    return 0;
}