#include<stdio.h>
int main() {
	int rounds;
	scanf("%d",&rounds);
	int leader, lead;
	int maxleader=0,maxlead=0;
	int a,b,suma=0,sumb=0;
	while(rounds--) {
		scanf("%d",&a);
		scanf("%d",&b);
		suma += a;
		sumb +=b;
		if(suma<sumb) {
			lead = sumb-suma;
			leader = 2;
		}
		else {
			lead = suma-sumb;
			leader = 1;
		}
		maxlead = maxlead>lead?maxlead:lead;
		if(maxlead == lead)
			maxleader = leader;
		
	}
	printf("%d %d\n",maxleader,maxlead);
	return 0;
}
	