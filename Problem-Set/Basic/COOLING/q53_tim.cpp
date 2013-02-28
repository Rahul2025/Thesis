#include<stdio.h>
int main()
{
    int a,b,c[31],d[31];
    scanf("%d",&a);
    while(a--)
    {
        scanf("%d",&b);
        for(int i=0;i<b;i++)
        {
            scanf("%d",&c[i]);
        }
        for(int j=0;j<b;j++)
        {
            scanf("%d",&d[j]);
        }
        int temp;
        for(int i=0;i<b;i++)
        {
            int min=c[i];
            for(int j=i+1;j<b;j++)
            {
                if(c[j]<min)
                {
                min=c[j];
                temp=c[i];
                c[i]=c[j];
                c[j]=temp;
                }
            }
        }
         for(int i=0;i<b;i++)
        {
            int min=d[i];
            for(int j=i+1;j<b;j++)
            {
                if(d[j]<min)
                {
                min=d[j];
                temp=d[i];
                d[i]=d[j];
                d[j]=temp;
                }
            }
        }
        int count1=0,count2=0,sum=0;
        while(count2!=b)
        {
            if(d[count2]<c[count1])
            {
                count2++;
            }
            else
            {
                count1++;
                count2++;
                sum++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}