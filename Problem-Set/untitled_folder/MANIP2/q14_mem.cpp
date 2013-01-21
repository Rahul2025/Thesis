#include<iostream>
int power(int a,int b)
{int i, val=1;for(i=1;i<=b;i++) val=val*5;return val;}
using namespace std;
int main()
{
  int t,n,binary[32];
  cin>>t;
  while(t--){
             int i=0,length=0,val=0,p;
             cin>>n;
             while(n)
             {
               binary[length++]=n%2;
               n/=2;
              }
             for(i=0;i<length;i++)
              val+=power(5,i+1)*binary[i];
              cout<<val<<endl;
             }
  return 0;           
}