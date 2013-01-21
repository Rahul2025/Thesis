#include<stdio.h>
#include<string.h>

int main()
{
	char extension[100][11],media[100][51];
	char filename[1000];
	int n,m,length;
	scanf("%d%d",&n,&m);

	for(int i=0;i<n;i++)
	{
		scanf("%s%s",extension[i],media[i]);
	}
	for(int i=0;i<m;i++)
	{
		int flag=-1;
		scanf("%s",filename);

		length=strlen(filename);
		for(int j=0;j<length;j++)
			if(filename[j] == '.')
			{
				flag=j;
			}
		if(flag == -1)
		{
			printf("unknown\n");
			continue;
		}
		bool check=true;
		char ext[100];
		char*p = &filename[flag+1];
		int s=0;
		while(*p != '\0')
		{
			ext[s] = *p;
			p++;
			s++;
		}
		ext[s++]='\0';
		for(int i=0;i<n;i++)
			if(!strcmp(ext,extension[i]))
			{
				printf("%s\n",media[i]);
				check=false;
				break;
			}
			if(check)
				printf("unknown\n");
	}
	return 0;
}


	