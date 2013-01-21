#include<stdio.h>
int main()
{
    int t,i,l;
    char s[100];
    scanf("%d",&t);
    while(t--)
    {
              scanf("%s",s);
              i=0;
              l=0;
              while(s[i])
              {
                         l+=s[i];
                         i++;
              }
              l=l/i;
              printf("%c\n",l);
    }
    return 0;
}      