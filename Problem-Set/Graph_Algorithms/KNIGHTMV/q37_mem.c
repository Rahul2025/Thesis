#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
    char array[10000],c;
    long int t;
    
    scanf("%ld",&t);
    scanf("%c",&c);
    
    while(t)
    {
          gets(array);
          if(((array[0]>='a') && (array[0]<='h')) && ((array[1]>='1') && (array[1]<='8')) && (array[2]=='-') && ((array[3]>='a') && (array[3]<='h')) && ((array[4]>='1') && (array[4]<='8')) && strlen(array)==5)

          {
                          
                              if((abs(array[0]-array[3])==1 && abs(array[1]-array[4])==2)||(abs(array[0]-array[3])==2 && abs(array[1]-array[4])==1))
                              {
                                 
                                     printf("Yes\n");
                                     
                              }
                                 else
                                 {
                                     printf("No\n");
                                     
                                 }
                              
      }
      else
      {
       printf("Error\n");
      }
      
      
   t--;
   
   
}

return 0;

}                          
                                          
                                                                                                                     