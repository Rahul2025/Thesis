#include<stdio.h>
#include<math.h>
int scan()
{
	int t=0;
	char c;
	c=getchar_unlocked();
	while(c<'0' || c>'9')
		c=getchar_unlocked();
	while(c>='0' && c<='9')
	{
		t=(t<<3)+(t<<1)+c-'0';
		c=getchar_unlocked();
	}
    return t;
}

int main()
{
	int p,s,t;
	float i,h;
	t=scan();
	while(t--)
	{
		p=scan();
		s=scan();
		i=((float)p)-sqrt(p*p-24*s);
		i=(float)i/12;
		h=(p/4)-(2*i);
		printf("%.2f\n",i*i*h);
	}
	return 0;
}
		
		