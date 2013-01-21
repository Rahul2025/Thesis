#include <stdio.h>
#include <math.h>
 
int main()
{
int T;
int N;
int triplets[3];
int i;
int time;
int n,rem;
 
scanf("%d",&T);
while(T) {
scanf("%d",&N);
time = 0;
for(i=0;i<N;i++) {
scanf("%d %d %d",&triplets[0],
&triplets[1],&triplets[2]);
if( time == 0) {
time = triplets[0] + triplets[1];
continue;
} /* if */
n = (time - triplets[0])/triplets[2];
rem = (time - triplets[0])%triplets[2];
//printf("value of n,rem : %d,%d when time was : %d and triplets[0] : %d triplets[2] : %d\n",n,rem,time,triplets[0],triplets[2]);
n = (rem > 0)? n+1:n;
n = (rem <= 0 && n < 0)? 0:n;
time += triplets[0] + (n*triplets[2]) -time + triplets[1];
} /* for */
printf("%d\n",time);
T--;
} /* while */
} 