#include<iostream>
using namespace std;
int palindrome(int);
int main()
{
int tc;
cin>>tc;
while(tc--)
{
int num;
cin>>num;
palindrome(++num);
}
return 0;
}

int palindrome(int num)
{
int digit ,rev=0,n;
n=num;
while(n!=0)
{
digit=n%10;
rev=rev*10+digit;
n=n/10;
}
if((num-rev)==0)
cout<<num<<endl;
else
palindrome(++num);
}