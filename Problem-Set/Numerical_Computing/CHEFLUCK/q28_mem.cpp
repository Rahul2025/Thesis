#include<iostream>

using namespace std;

int main()
{
  long long n,t;
  cin>>t;
  while(t--)
  { 
    cin>>n;
    while(n>0 && n%7!=0)
    {
      n-=4;
    } 
    if(n>=0)
      cout<<n<<endl;
    else
      cout<<"-1"<<endl;
  } 
}