/* Author: Karlheinz Jung */
/* Compiler: Borland Turbo C 2.01 */
/* Computer: Rabbit 286 */
/* Contest: April 2012 Long Contest */
/* Problem: Similar Graphs (SIMGRAPH) */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
int fall, n, t, k;
int a[100];
char z[1000];
time_t zeit;

time(&zeit);
srand(zeit);

for(gets(z),fall=atoi(z); fall--;)
	{
	gets(z);
	n=atoi(z);
	memset(a,0,sizeof(a));

	for(t=0; t<2*n; gets(z),t++);
	for(t=1; t<=n; printf("%d ",t++));
	puts("");

	for(k=0; k<n; k++)
		{
		while(1)
			{
			t=rand()%n+1;
			if(!a[t])
				{
				a[t]=1;
				break;
				}
			}
		printf("%d ",t);
		}
	puts("");
	}

return 0;
}