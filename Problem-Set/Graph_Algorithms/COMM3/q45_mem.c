#include <stdio.h>
#include <math.h>

main()
{
	int T;
	scanf("%d", &T);

	while(T-- > 0)
	{
		int R, count = 0, points[3][2];
		scanf("%d", &R);

		scanf("%d", &points[0][0]);
		scanf("%d", &points[0][1]);

		scanf("%d", &points[1][0]);
		scanf("%d", &points[1][1]);

		scanf("%d", &points[2][0]);
		scanf("%d", &points[2][1]);

		if(pow(points[1][1]-points[0][1], 2) + pow(points[1][0] - points[0][0], 2) <= R*R)
			count++;

		if(pow(points[2][1]-points[1][1], 2) + pow(points[2][0] - points[1][0], 2) <= R*R)
			count++;
		
		if(pow(points[2][1]-points[0][1], 2) + pow(points[2][0] - points[0][0], 2) <= R*R)
			count++;

		if(count >= 2)
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}
