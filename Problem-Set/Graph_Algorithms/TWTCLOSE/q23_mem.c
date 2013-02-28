#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int conv(char);
int main()
{
      int n,k,i,no,ans=0,open[1000],p;
      char str[11];
      scanf("%d %d",&n,&k);
      for(i=0;i<n;i++)
      {
                      open[i]=0;
      }
      while(k>0)
      {
                p=0;
                no=0;
                scanf("\n%[^\n]s",str);
                if(str[2]=='O')
                {
                        for(i=0;i<n;i++)
                        {
                                 open[i]=0;
                        }
                        ans=0;
                }
                else if(str[2]=='I')
                {
                        for(i=0;i<4;i++)
                        {
                                 if(str[6+i]=='0'||str[6+i]=='1'||str[6+i]=='2'||str[6+i]=='3'||str[6+i]=='4'||str[6+i]=='5'||str[6+i]=='6'||str[6+i]=='7'||str[6+i]=='8'||str[6+i]=='9')
                                 {
                                       p++;
                                 }
                                 else
                                 {
                                             break;
                                 }
                        }
                        for(i=0;i<p;i++)
                        {
                                 no=no+(conv(str[6+i])*pow(10,p-i-1));
                        }
                        if(open[no-1]==0)
                        {
                                 ans=ans+1;
                                 open[no-1]=1;
                        }
                        else if(open[no-1]==1)
                        {
                                 ans=ans-1;
                                 open[no-1]=0;
                        }
                }
                printf("\n%d",ans);
      		k--;
      }
      return 0;
}
int conv(char a)
{
    return a-48;
}