#include<stdio.h>
int main()
{
        int t;
        scanf("%d",&t);
        int n,num,i,max,maxi;
        while(t--)
        {
                int count[10001]={0};
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                        scanf("%d",&num);
                        count[num]++;
                }
                max=0;
                for(i=0;i<10001;i++)
                {

                        if(count[i]>max)
                        {
                                max=count[i];
                                maxi=i;
                        }
                }
                printf("%d %d\n",maxi,max);
        }




        return 0;
}
   