#include<stdio.h>
#include<string.h>
int main()
{
        char str[105];
        int i,k;
        gets(str);
        k=strlen(str);
        for(i=0;i<k;i++)
        {
                if(str[i]=='a'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='e')
                {
                        printf("%c",str[i]);
                        i=i+2;
                }
                else
                printf("%c",str[i]);
        }
        return 0;
}