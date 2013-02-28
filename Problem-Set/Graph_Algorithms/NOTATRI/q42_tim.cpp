#include <iostream>
#include<algorithm>

using namespace std;
const int MAX_SIZE = 20000;
static char input[MAX_SIZE];

struct readInput{
	char* CP;
	readInput(){
		int size = fread(input, 1, MAX_SIZE, stdin);
		CP = input;
	}
	int nextInt(){
		int gap = input + MAX_SIZE - CP;
		if (gap < 100){
			memcpy(input, CP, gap);
			fread(input + gap, 1, MAX_SIZE - gap, stdin);
			CP = input;
		}
		while (*CP < '0') CP++;
		int res = 0;
		while (*CP >= '0'){
			res = res * 10 + (*CP) - '0';
			CP++;
		}
		return res;
	}
};

void quicksort(int *a, int l, int r){
    if(l<r){
        int p=(l+r)/2;
		int s=l,t,pv=a[p];
		t=a[r];a[r]=a[p];a[p]=t;
		for(int i=l;i<r;i++)if(a[i]<pv){
			t=a[i];a[i]=a[s];a[s]=t;
			s++;
		}
		t=a[s];a[s]=a[r];a[r]=t;
		quicksort(a,l,s-1);
		quicksort(a,s+1,r);
	}
}


int n,a[2000],i,j,k,t,c; 

int sort_compare( const void *arg1, const void *arg2 ){
	return ( *((int *)arg1) - *((int *)arg2) );
}

int main(){
	readInput ri;
	do {
		n=ri.nextInt();
		//scanf("%i",&n);
		if(n>0){
			for(i=0;i<n;i++)
				a[i]=ri.nextInt();
				//scanf("%i",&a[i]);
			//quicksort(a,0,n-1);
			qsort(a,n,sizeof(int),sort_compare);
			c=0;
			for(i=n-1;i>1;i--){
				j=0;k=i-1;
				while(k>j){
					if(a[i]>a[j]+a[k]){
						c+=k-j;
						j++;
					}
					else k--;
				}
			}
			printf("%i\n",c);
		}
	}while(n!=0);
}