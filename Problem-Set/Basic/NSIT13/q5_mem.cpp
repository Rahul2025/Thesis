#include<stdio.h>

int main()
{
    int t=10,T,i,j,num,n[11];
    
    while(t--)
    {
        T=10;
        num=10;
        
        while(T--)
        {//printf("%d\n",T);
            scanf("%d",&n[T]);
            n[T]%=42;
        }
        //for(i=9;i>=0;i--)printf("%d ",n[i]);
        for(i=9;i>=0;i--)
        for(j=i-1;j>=0;j--)
        {
            if(n[i]!=-1)
            if(n[i]==n[j])
            {
                num--;
                n[j]=-1;
            }
        }
        
        printf("%d\n",num);
    }
    return 0;
}