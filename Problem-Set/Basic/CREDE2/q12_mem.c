#include <stdio.h>
#include <stdlib.h>
 
int sum(int a) {
	int t = a, sum = 0;
	while ( t ) {
		sum += (t % 10);
		t /= 10;
	}
	return sum;
}
 
int main() {
	int n, T, tmp, count, i, flag, max;
	scanf("%d", &T);
	
	while ( T-- ) {
		scanf("%d", &n);
		tmp = n;
		count = 0;
		flag = 0;
		while (tmp) {
			tmp /= 10;
			count++;
		}
		max = 9*count;
		for ( i = max; i > 0; i-- ) {
			tmp = n - i;
			if ( tmp + sum(tmp) == n ) {
				printf("%d\n", tmp);
				flag = 1;
				break;
			}
		}
		if ( flag == 0 )
			printf("NONE\n");
	}
	return 0;
}
 