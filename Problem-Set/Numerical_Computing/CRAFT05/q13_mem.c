#include<stdio.h>
#include<stdlib.h>



typedef struct digitPrice
{
 int digit1;
 int digit2;
 int price;               
};


int main()
{
 
 int t,number,i;
 
  int a,b,c,d,e;
  int price;
 
   int numberOfNails;
 
 struct digitPrice *result;
 
 result=(struct digitPrice*)malloc(sizeof(struct digitPrice)); 
  
 
 scanf("%d",&t);
 
 
 int flag;
 for(i=0;i<t;i++)
 {
   price=0;
   scanf("%d",&numberOfNails);
   scanf("%d%d%d",&b,&c,&d);
    a=9;
    number=0;
    flag=0;
    while(a)
    {
     e=9;                       
     while(e>=0)
      {
     number= a*10000+b*1000+c*100+d*10+e;
       if(number%numberOfNails==0)
        {
        flag=1;
         break;                          
        }
       e--;
      }  
     if(flag==1)
       break;                                   
                           
     a--;
    }
     if(!flag)
      number=0;
   
    if(number)
    {
     result[i].digit1= a;                      
     result[i].digit2= e;
     result[i].price=number/numberOfNails;
    }
    else
     result[i].price=number;
   
   
 }


 for(i=0;i<t;i++)
  if(result[i].price)
   printf("%d %d %d\n",result[i].digit1,result[i].digit2,result[i].price);
  else
   printf("%d\n",0);

 return 0;
}
