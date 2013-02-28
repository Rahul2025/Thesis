#include<stdio.h>
int main()
{
    int cases, temp1,k;
    scanf("%d",&cases);
    char word[101];
    while(cases--)
    {
             scanf("%s",&word);
             temp1=0;
             for(k=0; word[k]!='\0'; k++)
             {
                                 if(word[k]=='A'||word[k]=='D'||word[k]=='O'||word[k]=='P'||word[k]=='Q'||word[k]=='R')
                                          temp1++;
                                 else if(word[k]=='B')
                                      temp1+=2;
             }
             printf("%d\n",temp1);
    }
    return 0;
}