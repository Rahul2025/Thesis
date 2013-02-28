#include<iostream>
using namespace std;
int main()
{
    unsigned a,b,n,t,i,j,k,count,save;
    int ar[10];
    cin>>t;
    while(t--){
               cin>>a;
               count=0;
               for(;;){
                       count++;
                       save=a;
                       b=0;
                       while(a){
                                b=b*10+a%10;
                                a/=10;
                                }
                       a=save+b;
                       save=a;
                       i=0;
                       while(a){
                                ar[i++]=a%10;
                                a/=10;
                                }
                       a=save;
                       for(j=0,k=i-1;j<k;j++,k--){
                                                  if(ar[j]!=ar[k]) break;
                                                  }
                       if(j>=k){
                                cout<<count<<" "<<save<<endl;
                                break;
                                }
                       }
    }
    return 0;    
}