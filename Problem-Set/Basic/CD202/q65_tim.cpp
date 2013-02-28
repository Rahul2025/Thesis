#include<stdio.h>
int main()
{
	char a[110];
	gets(a);
	for(int i=0;a[i]!='\0';)
	{
		if(a[i]=='a' || a[i]=='e' || a[i]=='u'|| a[i]=='o'|| a[i]=='i')
		{
			printf("%c",a[i]);
			i=i+3;
		}
		else
		{
			printf("%c",a[i]);
			i++;
		}
	}	
}