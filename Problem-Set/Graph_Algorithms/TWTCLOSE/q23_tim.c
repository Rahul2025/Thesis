/* Author: Karlheinz Jung */
/* Compiler: Borland Turbo C 2.01 */
/* Computer: Rabbit 286 */
/* Contest: June 2012 Cook-off */
/* Problem: Closing the Tweets (TWTCLOSE) */

#include <stdio.h>
#include <string.h>

main()
{
int N, K, t, anz=0, x;
char stat[1010], komm[100], *p, *q;

scanf("%d %d",&N,&K);
memset(stat,0,sizeof(stat));
p=komm+2;

for(t=0; t<K; t++)
	{
	scanf("%s",komm);
	if(*p!='O')
		{
		scanf("%d",&x);
		q=stat+x;
		if(!*q)
			{
			anz++;
			*q=1;
			}
		else
			{
			anz--;
			*q=0;
			}
		}
	else
		{
		anz=0;
		memset(stat,0,sizeof(stat));
		}
	printf("%d\n",anz);
	}	

return 0;
}