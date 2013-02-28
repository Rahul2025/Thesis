# include<iostream>
using namespace std;
int main()
{
 unsigned long long int a,b,x,p,q,r,count;
 cin>>a>>b;
 while(a!=b)
  {
   p=1;q=2;count=0;r=0;
   while(r<=b)
    {
     r=p+q;
     p=q;
     q=r;
     if(a<=r && r<=b)
       count++;
    }
   cout<<count<<"\n";
   cin>>a>>b;
  }
 return 0;
}
       
      
   