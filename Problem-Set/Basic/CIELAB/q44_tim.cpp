#include<cstdio>


int main()
{
    int a ,b,ans;
    scanf("%d",&a);
    scanf("%d",&b);
    if(a>b)
    {                          
                           ans=a-b;
                           
                          
                                      if((ans%10)>5)
                                           printf("%d\n", ans-1);
                                      else 
                                           printf("%d\n", ans+1);
    }
  
    return 0;
}
    