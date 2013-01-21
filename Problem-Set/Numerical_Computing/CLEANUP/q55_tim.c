#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int readint()
{
    int cc = getc(stdin);
    for (;cc < '0' || cc > '9';)
            cc = getc(stdin);
    int ret = 0;
    for (;cc >= '0' && cc <= '9';)
    {
            ret = ret * 10 + cc - '0';
            cc = getc(stdin);
    }
    return ret;
}

int main(void)
{
    int T, n, m, i, val;

    T = readint();

    for(;T--;)
    {
        int arr[1001] = {0}, flag = 0;
        n = readint();
        m = readint();

        for(i=1; i<=m; i=i+1)
        {
            val = readint();
            arr[val] = -1;
        }

        for(i=1; i<=n; i=i+1)
        {
            if(arr[i] == 0)
            {
                if(flag == 0)
                    printf("%d ",i);
                flag = !flag;
            }
        }
        printf("\n");

        flag = 0;
        for(i=1; i<=n; i=i+1)
        {
            if(arr[i] == 0)
            {
                if(flag == 1)
                    printf("%d ",i);
                flag = !flag;
            }
        }
        printf("\n");
    }

    return 0;
}