#include "stdio.h"
#define gcx getchar_unlocked
inline int sc()
{
	int i=0;
	char c;
	c=gcx();
	while(c<'0'||c>'9')
		c=gcx();
	while(c>='0'&&c<='9'){
		i=(i<<3)+(i<<1)+c-'0';
		c=gcx();
	}
	return i;
}
int main()
{
	int t;
	t=sc();
	while(t--)
	{
		int n,pre,next,count=1;
		n=sc();
		pre=sc();
		while(--n)
		{
			next=sc();
			if(pre>=next)
			{
				pre=next;
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}