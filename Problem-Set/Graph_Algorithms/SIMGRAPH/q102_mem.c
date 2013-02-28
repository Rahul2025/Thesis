#include <stdio.h>
    int main()
    {
    int t, n, a[75][75], b[75][75], i , j;
    scanf("%d", &t);
    while(t--)
    {
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
    for(j = 0; j < n; j++)
    {
    scanf("%d", &a[i][j]);
    }
    }
    for(i = 0; i < n; i++)
    {
    for(j = 0; j < n; j++)
    {
    scanf("%d", &b[i][j]);
    }
    }
    for(i = 1; i <= n; i++)
    {
    printf("%d ", i);
    }
    printf("\n");
   for(i = 1; i <= n; i++)
    {
    printf("%d ", i);
    }
    printf("\n");
    }
    return 0;
    }  