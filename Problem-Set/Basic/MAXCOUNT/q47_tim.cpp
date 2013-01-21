#include <stdio.h>
#define min(a,b) a<b?a:b
#define BUF 4096
 
int input[100];
int hash[10000];
int max, feq;
 
char ibuf[BUF];
int ipt = BUF;
 
int readInt() 
{
    int n=0;
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
    if (ipt == BUF) {
	fread(ibuf, 1, BUF, stdin);
	ipt = 0;
	while (ipt < BUF && ibuf[ipt] < '0') ipt++;
    }
    while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
    if (ipt == BUF) {
	fread(ibuf, 1, BUF, stdin);
	ipt = 0;
	while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
    }
    return n;
}
 
int main()
{
    int i,j,n,t;
    //scanf("%d", &t);
    t=readInt();
    for(i=0; i<t; i++){
	//	scanf("%d", &n);
	n=readInt();
	for(j=0; j<n; j++){
	    input[j]=readInt();
	    //scanf("%d", &input[j]);
	    hash[input[j]]=0;
	}
	//for(j=0; j<n; j++) printf("%d ", input[j]);
	max=input[0];
	feq=1;
	hash[max]=1;
	for(j=1; j<n; j++){
	    hash[input[j]]++;
	    if(hash[input[j]]==feq)max=min(max, input[j]);
	    if(hash[input[j]]>feq){
		max=input[j];
		feq=hash[input[j]];
	    }
	}
	printf("%d %d\n", max, feq);
    }
    return 0;
}