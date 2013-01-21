#include<stdio.h>
int main()
 {
  int N,K,count=0,i,j,status[1001]={0},temp;

  char s[11],c;

  scanf("%d %d",&N,&K);

  c = getchar();

  for(i=0;i<K;i++)
  {
   gets(s);
   if(s[4]=='K')
    {
     temp=0;
     j=6;
     while(s[j]!='\0')
      {
       temp=temp*10+((int)(s[j]-'0'));
       j++;
      }
     if(status[temp]==0)
      {
       status[temp]=1;
       count++;
      }
     else
      {
       status[temp]=0;
       count--;
      }
    }
   else
    {
     temp=0;
     for(j=1;(j<=N)&&(temp<count);j++)
      {
       if(status[j]==1)
        {
         status[j]=0;
	 temp++;
        }
      }
     count = 0;
    }
   printf("%d\n",count);
  }
  return 0;
 }














