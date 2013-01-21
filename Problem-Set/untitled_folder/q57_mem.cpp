#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>
#include <set>
#include <ctime>
#include <queue>
#include <climits>
#include <iomanip>
#include <limits>
#include <iterator>
#include <stack>
#define LOCAL
#ifdef ONLINE_JUDGE
#undef LOCAL
#endif
#ifdef LOCAL
#define cin in
#define COUT(s) cout<<"----"<<s<<"----"<<endl
#endif
#ifndef LOCAL
#define COUT(s);
#endif
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
 
using namespace std;
 
const long long INFLL=numeric_limits<long long int>::max();
const int INF=numeric_limits<int>::max();
 
class comparaison1
{
    public:
    comparaison1(){}
    bool operator()(const int &a,const int &b)
    {
        return a>b;
    }
};
 
class comparaison2
{
    public:
    comparaison2(){}
    bool operator()(const int &a,const int &b)
    {
        return b>a;
    }
};
 
 
int main()
{
#ifdef LOCAL
    ifstream cin("ip.txt");
#endif
    int nb_cas;
    cin>>nb_cas;
    for(int c=0;c<nb_cas;c++)
    {
        string s;
        cin>>s;
        stack<char> st;
        for(int c=0;c<s.size();c++)
        {
            if(s[c]==')')
            {
                cout<<st.top();
                st.pop();
            }
            else if(s[c]>='a'&&s[c]<='z')
            {
                cout<<s[c];
            }
            else if(s[c]!='(')
            {
                st.push(s[c]);
            }
 
        }
        cout<<endl;
    }
}
 