#include<stdio.h>
int main()
{
    int T,N;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        if(N%2==1)
            N--;
        printf("%d\n",N);
    }
    return 0;
}