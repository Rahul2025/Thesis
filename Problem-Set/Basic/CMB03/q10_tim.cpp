#include<iostream>
#include<string>
using namespace std;

void main2(){
     string a,b;
     cin>>a;
     cin>>b;
     if(a.find(b,0)!=string::npos)
     cout<<1<<endl;
     else cout<<0<<endl;
     }

int main(){
    int i,T;
    cin>>T;
   for(int i=0;i<T;i++)
    main2();
    return 0;
    }