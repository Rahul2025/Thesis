#include<stdio.h>
#include<string.h>
int main()
{
    int i,n,q,l,j,flag;
    char fe[101][11],mt[101][51],fn[51];
    
    scanf("%d %d",&n,&q);
    for(i=0;i<n;i++)
        scanf("%s %s",&fe[i],&mt[i]);
    for(i=0;i<q;i++)
    {
        scanf("%s",&fn);
        char *str;flag=0;
        str=strrchr(fn,'.');
        if(str!='\0')
        {
        str++;
        for(j=0;j<n;j++)
        {
            if(strcmp(str,fe[j])==0)
            {
                printf("%s\n",mt[j]);flag=1;
            }
        }
        }
        if(flag==0)
            printf("unknown\n");
        
    }
    return 0;
}