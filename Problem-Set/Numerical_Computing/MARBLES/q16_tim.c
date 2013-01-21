#include <stdio.h>

int main()
{
    int t, i, n, k;;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &k);
        unsigned long long ans = 1;
        n--;
        k--;
        if((n-k)<k)
        {
            k=n-k;
        }
        for(i=0; i<k; i++)
        {
            ans*=n-i;
            ans/=(i+1);
        }
        printf("%llu\n", ans);
    }
    return 0;
}