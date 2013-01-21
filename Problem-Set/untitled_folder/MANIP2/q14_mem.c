#include<stdio.h>

int main()
{
    long arr[8000];
     int temp,t,i,n;
      
     arr[0]=' ';
     arr[1]=5;
       for(i=2;i<=8000;i++)
       {
           temp=(int)i/2;
           if(i%2==0)
               arr[i]=arr[temp]*5;   
           else 
                arr[i]=arr[temp]*5 + 5; 
       }
       scanf("%d",&t);
 
      while(t--)
       {
            scanf("%d",&n);
            printf("%ld\n",arr[n]);  
       }
return 0;
}