#include <iostream>

using namespace std;

int main()
{
    int t,n,k,a[100],i,j,c=0,sum=0,d;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>k;
        for(j=0;j<n;j++)
        {
            cin>>a[j];
        }
        for(j=0;j<n;j++)
        {
            sum=sum+a[j];
        }
        d=sum/k;
        for(j=0;j<n;j++)
        {
            if(sum%k>=a[j])
            {
                c++;
            }
        }
        if(c==0)
        {
            cout<<d<<"\n";
        }
        else
        {
            cout<<"-1\n";
        }
        sum=0;
        c=0;
    }

    return 0;
}