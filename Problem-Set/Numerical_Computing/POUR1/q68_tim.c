//By Mukul Gupta
//Pouring Water
#include<stdio.h>

#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b

int pourb(int a,int b,int c)
{
   long count=0;
   long a1=0,b1,i;
   b1=0;
   i=0;
    //b mein bharke a mein daalo
       while(1)
      {
      while(a1<a)
      {          b1=b;
                 count++;
                  //printf("%d %d\n",a1,b1);
                 a1+=b1;
                 b1=0; 
                 count++;
                 if (a1>=a)
                 break;
                  //printf("%d %d\n",a1,b1);
                 if (a1==c || b1==c)
                 return count;   
   
      }   
            if (a1==a)
            return -1;
            b1=a1-a;
            a1=a;

             //printf("%d %d\n",a1,b1);
            if (a1==c || b1==c)
                 return count;
            a1=0;   
            count++;
             //printf("%d %d\n",a1,b1);
            a1=b1;
            b1=0;
            count++;
             //printf("%d %d\n",a1,b1);
            
      }   
    
}

long poura(long a,long b,long c)
{
   long count=0;
   long a1=0,b1=0,i;
   
       count++;
       a1=a;
       if (a1==c || b1==c)
       return count;  
       while(1)
      {
               while(a1>b)
               {           //printf("%d %d\n",a1,b1);
                          b1=b;
                          a1=a1-b1;
                          count++;
                           //printf("%d %d\n",a1,b1);
                          if (a1==c || b1==c)
                          return count;  
                          count++;
                          b1=0;
                          
                           //printf("%d %d\n",a1,b1);
               }
      if (a1==b)
      return -1;
      b1=a1;
      a1=0;
      count++;
       //printf("%d %d\n",a1,b1);
      a1=a;
      count++;
       //printf("%d %d\n",a1,b1);
      a1=a-(b-b1);
      b1=b;
      count++;
      if (a1==c || b1==c)
      return count;  
       //printf("%d %d\n",a1,b1);
      b1=0;
      count++;
      }
    
}

int main()
{
 long t,a,b,c,a1,b1; 
 long temp1,temp2;  
 scanf("%ld",&t);
 while(t--)
 {
   scanf("%ld %ld %ld",&a1,&b1,&c);       
   a=a1>b1?a1:b1;
   b=a1<b1?a1:b1;       
   temp1=poura(a,b,c);
    //printf("\n");
   temp2=pourb(a,b,c);
    //printf("\nAnswer = %ld %ld\n",temp1,temp2);
   if (c==0)
   {printf("0\n");
   continue;
}
   if (c==a1 || c==b1)
   {printf("1\n");
   continue;
}
   if (temp1!=-1 && temp2!=-1)
   printf("%ld\n",(temp1<temp2)?temp1:temp2);
   else
   printf("%ld\n",(temp1>temp2)?temp1:temp2);
    //b mein bharke a mein daalo
   
 }   
    
 return 0;   
}