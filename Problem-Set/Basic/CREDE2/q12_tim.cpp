#include<stdio.h>
int main()
{
    int test;
    scanf("%d",&test);
    for(int t=0;t<test;t++)
    {
            int num;
            int ar[20];
            int ind=0;
            int temp;
            scanf("%d",&num);
            temp=num-60;
            int flag=0;
            for(;temp<=num+60;temp++)
            {
                                     int res=0,temp2=temp;
            while(temp2)
            {
                       res+=temp2%10;
                       temp2/=10;
            }
            res+=temp;
            if(res==num)
            {
                         printf("%d\n",temp);
                         flag=1;
                         break;
            }
            }
            if(flag)
            continue;
            printf("NONE\n");
    }
}