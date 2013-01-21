#include<stdio.h>
#include<string.h>
int main()
{
 long int n,x,l1,l2,flag,i,j;
 char a[10000],b[10000];
 scanf("%ld",&n);
 while(n--)
 {
  scanf("%s %s",a,b);
  l1=strlen(a);
  l2=strlen(b);
  for(i=0;i<l1;i++)
  {
   for(x=0;x<l2;x++)
   {
    j=i;
    flag=1;
    if(a[x+i]!=b[x])
	{
	 flag=0;
	 break;
	}
   }
   if(x==l2)
   {
    printf("1\n");
	break;
   }
  }
  if(flag==0)
  printf("0\n");
 }
return 0;
}
 
