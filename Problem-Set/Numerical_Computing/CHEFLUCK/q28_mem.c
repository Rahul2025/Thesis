#include<stdio.h>
//#include<conio.h>
int main()
{
    int t,n,flag,count,rem;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n<7)
        {
        if(n%4!=0)
        printf("-1\n");
        else
        printf("0\n");
        }
        
   else
   {
     flag=1;
     rem=n%7;
     count=n-rem;
     while(count>=0)
     {  
     if(rem%4==0)
     {
      printf("%d\n",count);
      flag=0;
      break;}
     else{         
     count=count-7;
     rem=n-count;
     }
     }
    if(flag)
    printf("-1\n");
}
}
//getch();
return 0;
}

          
      
                     