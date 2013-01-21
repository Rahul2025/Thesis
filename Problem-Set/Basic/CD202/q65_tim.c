#include<stdio.h>
#include<string.h>

int isvowel(int);

int main()
{
    int i=0,j=0;
    char code[105];
    char decode[105];
    scanf("%[^\n]s",code);
    int n=strlen(code);
    while(i<(n))
    {

            if(isvowel(code[i]))
            {decode[j++]=code[i];i+=3;}
            else {
            decode[j++]=code[i];i+=1;
            }
    }
    decode[j]='\0';
    printf("%s",decode);
    return 0;
}


int isvowel(int a)
{
    if(a==97 || a==101 || a==105 || a==111 || a==117)
    return (1);
    else
    return (0);
}