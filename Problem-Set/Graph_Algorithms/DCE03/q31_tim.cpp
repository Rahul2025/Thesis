#include<iostream>
#include<cmath>
using namespace std;
int primes[2100]={2,3,5,7,11,13,17,19,23};
int main() 
{
    long long n=9,k,a,b,c,d,e,f,prod=1,i,temp;
    float check;
    bool flag=false;
    for(i=25;i<=2100;i+=2)
    {
       check=sqrt(i);
       for(k=0;primes[k]<=check;k++)
       {
          if(i%primes[k]==0)
          {
             flag=false;
             break;
          }
          else
             flag=true;             
       }
       if(flag==true)
          primes[n++]=i;          
    }
    
    int t;
    cin>>t;
    while(t--)
    {
    cin>>b;
    b=b-1;
    a=2*b;
    c=b+1;
    prod=1;
    for(i=0;primes[i]<=a;i++)
    {
       d=e=f=0;
       long long pr1=1,j;
       temp=primes[i];
       while(a/temp != 0)
       {
          d+=a/temp;
          e+=b/temp;
          f+=c/temp;
          temp=temp*primes[i];
       }
       temp=primes[i];
       //cout<<temp<<" "<<d<<" "<<e<<" "<<f<<" "<<d-e-f<<endl;
       for(j=1;j<=(d-e-f);j++)
          pr1=(pr1*temp)%10000;
       prod=(prod*pr1)%10000;
    }
    cout<<prod<<endl;
    }
    return 0;
}