#include<stdio.h>

int rev(int m)
{
    int x=0;
    while(m)
    {
    x=x*10+(m%10);
    m=m/10;
    }
    return x;
}


int Pl(int m)
{
    int d;
    d=m-rev(m);
    if(d==0)
    return 1;
    else
    return 0;
}

int main()
{
    int t, a;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &a);
        a=a+1;
        while(Pl(a)!=1)
        {
            a++;
        }
        printf("%d\n", a);
    }
    return 0;
}
