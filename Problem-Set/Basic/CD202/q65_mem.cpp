#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
char input[100];
gets(input);
for(int i=0;i<strlen(input);i++){
        if(input[i]=='a' || input[i]=='e' ||input[i]=='i' ||input[i]=='o' ||input[i]=='u')
                                        { printf("%c",input[i]); i=i+2;}
        else
            printf("%c",input[i]);
        }
return 0;
}