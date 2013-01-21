#include<iostream>
using namespace std;

int f(int p)
{
    int cnt=0;
    while(p) { p=p&(p-1); cnt++; }
    return cnt;
}


main()
{
      int t,p,ans,rem,q;
      cin>>t;
      while(t--)
      {
                cin>>p;
                if(p>2048) {q=p/2048; rem=p%2048; ans=q+f(rem);}
                else ans=f(p);
                cout<<ans<<endl;
                }}
                