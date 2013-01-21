#include<iostream>
#include<stdio.h>

using namespace std;

int dishes[1001],chef[501],assist[501];

int chef_count =0,assist_count=0;

inline int read(){
	int n=0;
	char c;
	while(!isdigit(c=getchar()));
	while(isdigit(c)) {
		n=(n<<3)+(n<<1)+(c-'0');
		c=getchar();
	}
	return n;
}
int main(){
	int test =0, n=0,m=0, i= 0,num=0,flag=0;
	test = read();
	//cout<<test<<endl<<flush;
	while(test--){
		n = read();
		//cout<<n<<endl<<flush;
		m = read();
		//cout<<m<<endl<<flush;
		for(i=0;i<m;i++){
			num = read();
			//cout<<num<<endl<<flush;
			dishes[num]=-1;
		}
		chef_count = 0, assist_count = 0;
		for(i=1,flag=0;i<=n;i++){
			if(dishes[i]!=-1){
				if(flag==0){
					chef[chef_count++] = i;
					flag = 1;
				}
				else{
					assist[assist_count++] = i;
					flag = 0;
				}
			}
		}
		for(i=0;i<chef_count;i++) printf("%d ",chef[i]);
		printf("\n");
		for(i=0;i<assist_count;i++) printf("%d ",assist[i]);
		printf("\n");
		for(i=1;i<=n;i++) dishes[i]=0;
	}
	return(0);
}