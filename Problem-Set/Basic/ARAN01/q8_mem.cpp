//Riled
#include <iostream>
using namespace std;
int main()
{
    int t;
    string s;int sum;
    cin >> t;
    while(t--)
    {
              sum=0;
              cin >> s;
              for(int i=0;i<s.size();i++)
              sum+=(int)s[i];
              sum/=s.size();
              cout << (char)sum << endl;    
    }
    return 0;
    
}