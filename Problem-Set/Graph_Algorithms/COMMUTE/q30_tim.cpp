#include<iostream>
using namespace std;

int small(int a,int b)
{
    if(a%b==0)
        return a/b;
    else
        return (a/b+1);
}

int main()
{
    int test,n,x,l,f,t;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        scanf("%d%d%d",&x,&l,&f);
        t=x+l;
        n--;
        while(n--)
        {
            scanf("%d%d%d",&x,&l,&f);
            if(x>t)
                t=x;
            else
                t=x+small(t-x,f)*f;
            t+=l;
        }
        printf("%d\n",t);
    }
    return 0;
}