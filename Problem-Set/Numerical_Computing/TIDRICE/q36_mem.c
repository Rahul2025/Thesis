#include<string.h>
int main()
{
    int t,n,i,j,l;
    char a[100][21],b[100][2];
    scanf("%d",&t);
    while(t--)
    {
              scanf("%d",&n);
              for(i=0;i<n;i++)
              scanf("%s%s",a[i],b[i]);
              l=0;
              for(i=0;i<n;i++)
              {
                              if(b[i][0]=='+')
                              l++;
                              else
                              l--;
                              j=i-1;
                              while(j>=0&&strcmp(a[i],a[j]))
                              j--;
                              if(j>=0)
                              {
                                      if(b[j][0]=='+')
                                      l--;
                                      else
                                      l++;
                              }
              }
              printf("%d\n",l);
    }
    return 0;
}