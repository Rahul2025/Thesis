#include<iostream>
using namespace std;
int x,y,z,t;
int small(int x,int y);

int gcd(int a,int b)        {    if(b==0) return a ; else return gcd(b,a%b); }

int main()
{   cin>>t;
while(t--)
{
    int count1,count2;
    x=y=z=count1=count2=0;
    cin>>x>>y>>z;
    if(z>x&&z>y) { cout<<"-1\n"; continue; }
    else if(x==z||y==z)   {  cout<<"1\n";continue; }
    else {
    int flag=z%gcd(x,y); //cout<<gcd(x,y)
    if(flag!=0) { cout<<"-1\n"; continue; }
    else{
     count1=small(0,0);
     int temp=x ; x=y  ; y=temp;
     count2=small(0,0);
     if(count1<=count2) { cout<<count1<<"\n";}
     else cout<<count2<<"\n";
    }
    }

}
return 0;
}





int small(int a,int b)
{
    if(a==z||b==z)                                             {return 0;}
    else if(a==0&&b==0)           { a=x ; return 1+small(a,b);}
    else if(b==y)                   {b=0; return 1+small(a,b);}
    else if(a==0)                   {a=x;return 1+small(a,b);}
    else if(a!=0&&b!=y)
    { if((a-(y-b))>=0)
                      { a=a-(y-b); b=y;  return 1+small(a,b); }
      else
                           { b=b+a; a=0;  return 1+small(a,b);}

    }
}
