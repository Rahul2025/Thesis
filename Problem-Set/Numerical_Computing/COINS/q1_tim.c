// filename ::q1_tim.c

#include <stdio.h>
#define LONG_NUM 1000

long long int cache[3000][2];
long long int dynmem[LONG_NUM];
int cacheptr = 0;

int incache(long long int n)
{
	unsigned int i;
	for (i=0; i<cacheptr; i++) {
		if(cache[i][0] == n)
			return i;
	}
	return -1;
}

long long int compute(long long int i)
{
	long long int c,res;
	int k;
	if(i==0) return 0;
	if(i==1) return 1;
	if(i< LONG_NUM)
	{
		if(dynmem[i] != 0)
			return dynmem[i];
	}
	k = incache(i);
	if(k!= -1)
	{
		return cache[k][1];
	}
	c = compute(i/2)+compute(i/3)+compute(i/4);
	res = ((i > c)?i:c);
	if(i< LONG_NUM)
	{
		dynmem[i] = res;
	}
	else if(cacheptr < 3000)
	{
		cache[cacheptr][0] = i;
		cache[cacheptr][1] = res;
		cacheptr++;
	}
	return res;
}


int main () {
    long long int num;
	int i=0;
	while(i<10)
	{
		if((scanf("%lld",&num)) != 1)
			break;
		printf("%llu\n",compute(num));
		i++;
	}
    return 0;
}