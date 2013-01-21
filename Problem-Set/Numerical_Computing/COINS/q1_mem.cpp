// filename :: q1_mem.cpp


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <climits>
#include <cstdlib>

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)

using namespace std;
map<LL,LL> memorization;

LL rfind_max(int currency)
{
	map<long long,long long>::iterator itr=memorization.find(currency);
	//cout<<currency<<endl;
	LL answer=0;
	if (currency<12)
		return currency;
	else
	{
		if(itr!=memorization.end())
		{
			answer=(*itr).second;
		}
		else
			answer=rfind_max(currency>>1)+rfind_max(currency/3)+rfind_max(currency>>2);
		memorization[currency]=answer;
		if(answer<=currency)
			return currency;
		else
			return answer;
	}
}
/*int ifind_max(int currency)
{
	int answer=currency;
	int prevanswer=currency;
	stack<int> currencies;

	return prevanswer;
}*/
int main (int argc, char ** argv)
{
	//Rd("data.in");
	LL currency =0;
	while(scanf("%lld",&currency)!=EOF)
	{
		LL result=0;
		result=rfind_max(currency);
		printf("%lld\n",result);
	}
	return 0;
}