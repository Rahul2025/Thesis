#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#include<map>
#include<vector>
#include<algorithm>
#include<queue>


using namespace std;
#define S scanf
#define Si(i) scanf("%d",&i)
#define P printf

#define Vi vector<int>
#define PUB push_back
#define F(i,a,b) for(int i=a;i<b;i++ )

int main(){
long long int a,b;
cin>>a>>b;
int c=abs(a-b);
char ar[16];
sprintf(ar,"%d",c);
c=strlen(ar);

if(ar[c-1]=='2')
ar[c-1]='1';
else
ar[c-1]='2';

cout<<ar;

    }