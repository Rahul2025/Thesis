#include<iostream>
using namespace std;

int main()
{
    int n,t,x,y,z,p,i,flag,p1;
    cin>>t;
    while(t--){
               cin>>n>>x>>y>>z;
               i=1;
               p=n*i;
               flag=0;
               while(p<10000){ i++; p=n*i; }
               for(;p<100000;i++){
                       p=n*i;
                       if((((p-p%10)/10)%10==z)&&(((p-p%100)/100)%10==y)
                       &&(((p-p%1000)/1000)%10==x))
                                                   {
                                                   flag=1;
                                                   p1=p;
                                                   }
                       }
               if(!flag) cout<<"0"<<endl;
               else cout<<p1/10000<<" "<<p1%10<<" "<<p1/n<<endl;
               }   
    return 0;
}