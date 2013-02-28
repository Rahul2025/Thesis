#include<stdio.h>
int main()
{
    int t,n,c,sum,x,a,min;
    scanf("%d",&t);
    while(t--)
    {
        min=1000;
        sum=0;
        scanf("%d %d",&n,&c);
        for(x=0;x<n;x++)
        {
            scanf("%d",&a);
            sum+=a;
            //printf("a=%d\n",a);
            if(a<min)
                min=a;
        }
        if(sum/c==0||sum%c>=min)
            printf("-1\n");
        else
            printf("%d\n",sum/c);
    }
    return 0;
}