#include<stdio.h>
int main()
{
    char arr[100];
    int i,hole;
    int t;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%s",arr);
       for(i=0,hole=0;arr[i];i++)
       {
	   if(arr[i]=='A'||arr[i]=='D'||arr[i]=='O'||arr[i]=='P'||arr[i]=='R'||arr[i]=='Q')
	   hole++;
	   else if(arr[i]=='B')
	   hole+=2;
       }
       printf("%d\n",hole);
    }
    return 0;
}