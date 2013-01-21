#include<iostream>
//#include<conio>
using namespace std;
int strlen(char *z)
{
  int j=0;
  while(z[j]!='\0')
   j++;
  return j;
}
int main()
{
    char a[100];
    
int b,c;
cin>>c;
while(c--)
{cin>>a;
b=0;
for(int i=0;i<strlen(a);i++)
{
        b=b+a[i];
}
cout<<char((b/strlen(a)))<<endl;
}
return 0;
}