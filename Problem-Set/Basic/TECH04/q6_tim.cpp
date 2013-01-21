#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    char a[25],b[25];
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s %s",a,b);
        n=strlen(a);
        sort(a,a+n);
        n=strlen(b);
        sort(b,b+n);
        if(strcmp(a,b)==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
