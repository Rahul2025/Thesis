#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define BUFFERSMALL	100
#define BUFFERSIZE	1000000
 
/* 
class QuickRead
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
			n = n*10+(*pBuf++-'0');
		pBuf++;
	}
 
	inline void LineAsVectorInt(int numInts, vector<int> &line)
	{
		int n;
		ReadLine();
		while ( numInts-- )
		{
			n = 0;
			while (*pBuf >= '0')
				n = n*10+(*pBuf++-'0');
			pBuf++;
			line.push_back(n);
		}
	}
 
	QuickRead() {};
};
*/
int main(){
	int test = 0, i = 0, N = 0, num = 0,flag = 0;
	
	int num_leaves = 0;

	//QuickRead qr;
	scanf("%d\n",&test);
	//qr.LineAsInt(test);
	//cout<<test<<endl<<flush;
	
	while(test--){
		scanf("%d\n",&N);
		//qr.LineAsInt(N);
		//cout<<N<<endl<<flush;
		//qr.ReadLine();
		num_leaves = 1;
		flag = 0;
		while(N--){
			scanf("%d",&num);

			//qr.NextInt(num);
			//cout<<num<<endl<<flush;
			if(num> num_leaves){
				flag=1;
				while(N--) scanf("%d",&num);
				break;
			}
			num_leaves -= num;
			num_leaves <<= 1;
		}
		if(flag||num_leaves) printf("No\n");
		else printf("Yes\n");
	}
	return(0);
}