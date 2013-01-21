#include<stdio.h>
int main()
{
    int a,b;
scanf("%d",&a);
  while(a--)
  {
  scanf("%d",&b);    
  if(b%7==0)
  {
    printf("%d\n",b);        
  }
  else if(b%7==1)
  {
       if(b<7)
       printf("-1\n");
       else
       printf("%d\n",7*((b/7)-1));     
  }
  else if(b%7==2)
  {
       if(b<10)
       printf("-1\n");
       else
       printf("%d\n",7*((b/7)-2));
  }
  else if(b%7==3)
  {
       if(b<18)
       printf("-1\n");
       else
       printf("%d\n",7*((b/7)-3));
  }
  else if(b%7==4)
  {
       printf("%d\n",7*(b/7)); 
  }
  else if(b%7==5)
  {
       if(b<6)
       printf("-1\n");
       else
       printf("%d\n",7*((b/7)-1));
  }
  else if(b%7==6)
  {
       if(b<14)
       printf("-1\n");
       else
       printf("%d\n",7*((b/7)-2));
  }
  }
}