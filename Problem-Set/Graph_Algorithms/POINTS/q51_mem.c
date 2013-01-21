#include <math.h>
#include <string.h>
#include<stdio.h>

int main()
{
	unsigned short int num_testcases,i,j;
	// The number of testcases.
//printf ("Start \n");
	scanf ("%hu", &num_testcases);
//printf ("Read test cases : %hu \n",num_testcases);
	unsigned short int  buf [10001][3];
//printf ("Allocated buf \n");

	for (i=0; i<num_testcases ; i++)
	{
	//	char line[2];
		//Eat up a blank line
//		fgets(line,2,stdin);
		memset(buf,0,sizeof(buf));
//printf ("Memset buf \n");
//		 for(j=0; j<10001; j++)
	//	 	printf("%hu :%hu %hu %hu \n",j ,buf[j][0], buf[j][1], buf[j][2]);

		unsigned int num_points, k;
		//Get number of points
		scanf("%u", &num_points);
//printf ("Read test case points : %u \n",num_points);

		//Read in the points
		for(k=0; k<num_points; k++)
		{
			unsigned short int x, y;
			scanf("%hu%hu",&x,&y);
			if(buf[x][2] == 0)
			{
//			printf ("%hu %hu \n", x,y);
				buf[x][0] = buf[x][1] = y;
				buf[x][2] = 1;
			}
			else if (buf[x][0] > y)
				buf[x][0] = y;
			else if (buf[x][1] < y)
				buf[x][1] = y;

		}
	//	 for(j=0; j<10001; j++)
		// 	printf("%hu :%hu %hu %hu \n",j ,buf[j][0], buf[j][1], buf[j][2]);

		j = 0;

		while(buf[j][2] == 0)
			j++;

		double d =  buf[j][1]- buf[j][0] ;
		unsigned short int prevx = j;
		unsigned short int prevy = buf[j][0];
		j++;

		for(; j<10001; j++)
		{
			if(buf[j][2] != 0)
			{
				unsigned int tempx = j - prevx;
				unsigned int tempy = buf[j][1] - prevy;
				d += sqrt( (tempx * tempx) + ( tempy * tempy ) );
				d += ( buf[j][1]- buf[j][0] );
				prevx = j;
				prevy = buf[j][0];
			}
		}
		printf ("%.2f\n", d);
	}
	return 0;
}