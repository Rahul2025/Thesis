/****************************************************************
Author           : Ishan Dutta
Email            : ishandutta2007@gmail.com
Facebook account : http://www.facebook.com/ishan.dutta
Blog             : tessellationsoftechnology.wordpress.com
Topcoder Handle  : Ishandutta2007
Codeforces Handle: ishandutta2007
Codechef Username: ishandutta2007
Spoj Username    : ishandutta2007
UVA Username     : ishandutta2007
*****************************************************************/
/*******************************************************************/
// \_/\_/\_/\_/\_/\_/\_/\_/---Headers---\_/\_/\_/\_/\_/\_/\_/\_/
/*******************************************************************/

//C headers
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<cctype>
#include<cassert>
#include<climits>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<clocale>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>

//containers
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<complex>
#include<string>
#include<stack>
#include<bitset>
#include<istream>
#include<valarray>

//IOs
#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream>
#include<exception>
#include<ios>
#include<iosfwd>
#include<ostream>
#include<iterator>
#include<stdexcept>
#include<streambuf>

//algorithm & miscellaneous
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<limits>
#include<locale>
#include<memory>
#include<new>

/********************************************************************/
// \_/\_/\_/\_/\_/\_/\_/---Frequently used macros---\_/\_/\_/\_/\_/\_/\_/
/********************************************************************/

#define MOD 1000000007
#define INF 1000000000

/********************************************************************/
// \_/\_/\_/\_/\_/\_/\_/\_/\_/---Shorthands---\_/\_/\_/\_/\_/\_/\_/\_/\_/
/********************************************************************/

#define ll long long
#define F first
#define S second
#define PB push_back
#define PPB pop_back
#define MP make_pair

#define SZ(c)       (c).size()
#define reset(x)     memset((x),0,sizeof(x));
#define negset(x)    memset((x),-1,sizeof(x));
#define set(x)       memset((x),1,sizeof(x));

#define ALL(x)      (x).begin(),(x).end()
#define SORT(x)     sort(ALL(x))
#define REVERSE(c)  reverse(ALL(c))

#define VAR(a,b)    typeof(b) a=(b)
#define FOR(i,a,b)  for(VAR(i,b);i<=(b);++i)
#define REP(i,n)    FOR(i,0,(n-1))

#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define REPD(i,n)   FOR(i,(n-1),0)

#define IT(it,x)    for(typeof((x).begin()) it = (x).begin();it!=(x).end();++it)  

#define tst int T;scanf("%d",&T);for(int testno=1;testno<=T;testno++)
#define s(x)      scanf("%d",&x)
#define sl(x)     scanf("%lld",&x)
#define ss(x)     scanf("%s",x)

#define p(x)      printf("%d",x)
#define pl(x)     printf("%lld",x)
#define ps(x)     printf("%s",x)

#define pn(x)     printf("%d\n",x)
#define pln(x)    printf("%lld\n",x)
#define psn(x)    printf("%s\n",x)

#define sp system("PAUSE")

/********************************************************************/
// \_/\_/\_/\_/\_/---Fast IO using getchar_unlocked---\_/\_/\_/\_/\_/
/********************************************************************/
/*
int gi(){
   int c = 'a';
   while (!(c >= '0' && c <= '9') && c != '-') c = getchar_unlocked();//();//
   int c2;
   if (c != '-')
     c2 = c;
   else
     c2 = '0';
   int res = 0;
   while((c2 >= '0' && c2 <= '9')){
     res = (res << 3) + (res << 1) + (c2 - '0');
     c2 = getchar_unlocked();//();//
   }
   return res * (c == '-' ? -1 : 1);
}
*/
using namespace std;
/********************************************************************/
// \_/\_/\_/\_/\_/\_/---Actual Code Starts Here---\_/\_/\_/\_/\_/\_/
/********************************************************************/
char a[10000];
int main(){
  int t;scanf("%d",&t);getchar();for(int j=0;j<t;j++){
//    char g=getchar();
//    if(g==' '){psn("Error");gets(a+1);continue;}
//    else a[0]=g;
    gets(a);
    int l=strlen(a);    
    if(l!=5 || a[2]!='-' || 
       !('a'<=a[0] && a[0]<='h') || !('a'<=a[3] && a[3]<='h') || 
       !('1'<=a[1] && a[1]<='8') || !('1'<=a[4] && a[4]<='8') )
      {psn("Error");continue;}
    if(abs(a[0]-a[3])==0 || abs(a[1]-a[4])==0){psn("No");continue;}
    if(abs(a[0]-a[3])+abs(a[1]-a[4])==3){psn("Yes");continue;}
    psn("No");
  }
//sp;
  return 0; 
}

