#include<iostream>
using namespace std;
#include<algorithm>
int n,k;
int emt[1001];
int solve(int i,int k)
{
    if(emt[i]==k || k==0)
    return 1;
    if(emt[i]>k)
    return 0;

    for(;i<n;i++)
    {
        if(emt[i]>k)
        return 0;
        else if(solve(i+1,k-emt[i]))
        return 1;

    }
    return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    //cin>>t;
    while(t--)
    {
        //cin>>n>>k;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
        scanf("%d",&emt[i]);
        //cin>>emt[i];
        sort(emt,emt+n);
        printf("%d\n",solve(0,k));
    }
}