#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int main(){
	char str[11];
	int t=5,u,v,x,y;
	cin>>t;
	gets(str);
	for(int i=0; i<t; i++){
		gets(str);
		if(strlen(str) != 5)
			cout<<"Error\n";
		else if((str[2] != 45)||(str[0]>104)||(str[0]<97)||(str[3]>104)||(str[3]<97)||(str[1]>56)||(str[1]<49)||(str[4]>56)||(str[4]<49))
			cout<<"Error\n";
		else{
			u=str[0]; v=str[1];
			x=str[3]; y=str[4];
			x=x-u;
			y=y-v;
			//cout<<x<<" "<<y<<endl;
			if(x<0) x=x*-1;
			if(y<0) y=y*-1;
			if(((x==1)&&(y==2))||((x==2)&&(y==1)))
				cout<<"Yes\n";
			else
				cout<<"No\n";
		}
	}
	return 0;
}