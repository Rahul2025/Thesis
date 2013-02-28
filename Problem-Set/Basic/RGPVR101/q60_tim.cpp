#include<iostream>
using namespace std;
void printcode(string s);
int main()
{
    int test , i;
    cin >> test;
    for(i = 0 ; i< test ; i++)
    {
          string s; cin >> s;
       printcode(s);   
    }
}
void printcode(string s)
{
     int length = s.length();int i;
     for( i = length/2 ; i >= 1 ; i--)
     {
          cout <<  s[i-1];
      }
      for( i = length ; i > length/2 ; i--)
      {
           cout << s[i-1] ;
       }
       cout << endl ;
 }