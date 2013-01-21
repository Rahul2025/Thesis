#include <stdio.h>

#define fill(x, xc) (x = xc)
#define empty(x) (x = 0)

void pour(int *x, int xc, int *y, int yc) {
	int spaceInY = yc - *y;
	if(spaceInY <= *x) {
		*x -= spaceInY;
		*y += spaceInY;
	}
	else {
		*y += *x;
		*x = 0;
	}
}

int main() {
	unsigned int nCases, a, b, c, ac, bc, x, y, xc, yc, flag;
	long nSteps, nSteps1, nSteps2;
	scanf("%d", &nCases);
	while(nCases--) {
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);
		ac = a; bc = b;
		nSteps = -1;
		if(c <= a || c <= b) {
			if(c == 0)
				nSteps = 0;
			else if(a == 0 && b == 0)
				nSteps = -1;
			else if(c == a || c == b)
				nSteps = 1;
			else if((a-b) == c || (b-a) == c)
				nSteps = 2;
			else if(a == 0) {
				if(b == c)
					nSteps = 1;
			}
			else if(b == 0) {
				if(c == a)
					nSteps = 1;
			}
			else {
				nSteps1 = nSteps2 = 0;
				x = b; xc = bc;
				y = a; yc = ac;
				a = b = x = y = 0;
				flag = 1;
				fill(a, ac);	nSteps1++;
				while(flag == 1) {
					while(b != bc) {
						pour(&a, ac, &b, bc);	nSteps1++;
						if(a == c || b == c) {
							nSteps = nSteps1;
							flag = 0;
							break;
						}
						if(a == 0) {
							fill(a, ac);	nSteps1++;
						}
					}
					if(a != c && b != c) {
						empty(b);	nSteps1++;
					}
					if(a == ac && b == 0) {
						flag = 2;
						break;
					}
				}
				flag = 1;
				fill(x, xc);	nSteps2++;
				while(flag == 1) {
					while(y != yc) {
						pour(&x, xc, &y, yc);	nSteps2++;
						if(x == c || y == c) {
							nSteps = nSteps2;
							flag = 0;
							break;
						}
						if(x == 0) {
							fill(x, xc);	nSteps2++;
						}
					}
					if(x != c && y != c) {
						empty(y);	nSteps2++;
					}
					if(x == xc && y == 0) {
						flag = 2;
						break;
					}
				}
				if(flag == 0)
					nSteps = (nSteps1 < nSteps2) ? nSteps1 : nSteps2;
			}
		}
		printf("%ld\n", nSteps);
	}
	return 0;
}