# include<stdio.h>
//# include<conio.h>
# include<string.h>

int main()
{
    int arr[91];
    int T,l,c=0,i;
    char s[100];
    for(i=0;i<26;i++)
    {
          //  printf("\ni=%d",i);
            if(i==1)
                 arr[i+65]=2;
            else if((i==0)||(i==3)||(i==14)||(i==15)||(i==16)||(i==17))
                 arr[i+65]=1;
            else
                 arr[i+65]=0;
    }
    scanf("%d",&T);
    if(T>40)
           return 0;
    for(i=1;i<=T;i++)
    {
           // printf("Enter String:");
            scanf("%s",s);
            l=strlen(s);
            if(l>=100)
                   return 0;
            for(int j=0;j<l;j++)
            {
                    if((int)s[j]<65||(int)s[j]>91)
                           return 0;
                    if(s[j]==' ')
                           return 0;
                    c=c+arr[(int)s[j]];
            }
            printf("%d\n",c);
            c=0;
    }
  //  getch();
    return 0;
}
                         
            