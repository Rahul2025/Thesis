/*Correctness of Knight Move*/

#include<stdio.h>

int main()
{
	char line[15];
	int diffx,diffy,T;
	scanf("%d",&T);
	gets(line);
	while(T--)
	{
		gets(line);
		if(((line[0]>='a') && (line[0]<='h')) && ((line[1]>='1') && (line[1]<='8')) && (line[2]=='-') && ((line[3]>='a') && (line[3]<='h')) && ((line[4]>='1') && (line[4]<='8')) && (line[5]=='\0'))
		{
			diffx=line[3]-line[0];
			diffy=line[4]-line[1];
			if(diffx<0)
				diffx*=-1;
			if(diffy<0)
				diffy*=-1;
			if(((diffx==2) && (diffy==1)) || ((diffx==1) && (diffy==2)))
				puts("Yes");
			else
				puts("No");
		}
		else
			puts("Error");
	}
	return 0;
}