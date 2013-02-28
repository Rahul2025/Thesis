#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int t;
	int arr[]={1,2,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0};
	int sum=0;
	cin>>t;
	while(t--){
		sum=0;
		string a;
		cin>>a;
		for(int i=0;i<a.length();i++)
			sum+=arr[a[i]-65];
		cout<<sum<<endl;
	}
	return 0;
}