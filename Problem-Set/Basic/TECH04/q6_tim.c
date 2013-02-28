#include<stdio.h>
#include<string.h>
 
int main()
{
  int t,i,j,k,a[27]={0},flag;
  char s[22],d[22];
  scanf("%d",&t);
  while(t--)
  {
    scanf("%s %s",s,d);
    flag=0;
    j=strlen(s);
    k=strlen(d);
     if(j!=k)
      printf("NO\n");
    else{
      for(i=0;i<j;i++)
      {
	a[(int)s[i]-'a']++;
	a[(int)d[i]-'a']--;
      }
      for(i=0;i<26;i++)
      {
	  if(a[i]!=0){flag=1;}
	  a[i]=0;
      }
      if(flag!=1)
	printf("YES\n");
      else
	printf("NO\n");
    }
  }
  return 0;
} 