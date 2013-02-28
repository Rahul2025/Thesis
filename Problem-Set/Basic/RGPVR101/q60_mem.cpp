#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    char ch[51];
    while(t--)
    {
              scanf("%s",&ch);
              for(int i=0;i<strlen(ch)/2;i++)
                 printf("%c",ch[(strlen(ch)/2)-1-i]);
              
              for(int i=strlen(ch)-1;i>=strlen(ch)/2;i--)
                      printf("%c",ch[i]);
    
                      printf("\n");
    }
    return 0;
    }