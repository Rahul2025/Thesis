#include<stdio.h>
#include<string.h>

 int main()
 {
     
     int n,t,i,j;
     scanf("%d",&n);
     fflush(stdin); 
      
     char a[n][1000],c;
     char temp[1000]; 
    for(i=0;i<n;i++)
      {
        scanf("%s",a[i]);
        fflush(stdin);
        
                   
        t=0;
       
       for(j=0;j<strlen(a[i]);j++)
            {
             c=a[i][j];                     
             t=t+c;
             
             }
     printf("%c\n",t/strlen(a[i]));
} 
     return 0;
}               