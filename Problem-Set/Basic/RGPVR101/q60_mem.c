#include<stdio.h>
#include<string.h>
int main()

{
  int t,i,j;
 char str[51];
 scanf("%d",&t);
 while(t--)
{
  scanf("%s",str);
  i=strlen(str);
  for(j=i/2-1;j>=0;j--)
    printf("%c",str[j]);
   for(j=i-1;j>=i/2;j--)
   printf("%c",str[j]);
    printf("\n");       
 }

 return 0;
}
     