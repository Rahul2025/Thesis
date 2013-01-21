#include <cstdio>
#include <cstdlib>
#include <math.h>
using namespace std;

#define SUPER_LEAN
//#define LEAN
//#define SAFE
//#define SUPER_SAFE

#ifdef SUPER_LEAN
#define BUFFERSMALL	20
#define BUFFERSIZE	20
#elif LEAN
#define BUFFERSMALL	20
#define BUFFERSIZE	100
#elif SAFE
#define BUFFERSMALL	50
#define BUFFERSIZE	10000
#elif SUPER_SAFE
#define BUFFERSMALL	100
#define BUFFERSIZE	100000
#endif



class AllarRead
{
public:
	char szBUFFER[BUFFERSIZE];
	char *pBuf;

	inline void LineAsInt(int &lint) { lint = atoi(fgets(szBUFFER, BUFFERSMALL, stdin)); }
	inline void ReadLine() { fgets(szBUFFER, BUFFERSIZE, stdin); pBuf = szBUFFER;}

	inline void NextInt(int &n)
	{
		n = 0;
		while (*pBuf >= '0')
			n = (n << 3) + (n << 1) + (*pBuf++-'0');
		pBuf++;
	}

	AllarRead() {};
};



int main()
{
	AllarRead ar;
	int t, x = 0, y = 0, n, m, winner, lead = 0;

	ar.LineAsInt(t);

	while (t--)
	{
		ar.ReadLine();
		ar.NextInt(n);
		ar.NextInt(m);
		x+=n;
		y+=m;
		
		int leadtest = abs(x-y);
		if (leadtest > lead)
		{
			lead = leadtest;
			winner = x<y;
		}
	}

	printf("%d %d",winner+1,lead);

}