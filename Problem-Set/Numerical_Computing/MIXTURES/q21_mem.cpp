#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

typedef struct node {
	int a, d;
}node;

int main(){
	int t,n;
	node arr[101][101];
	int temp,x,y;
	int ff,k,i,j;
	
	while(EOF != scanf("%d",&n)){
		/*		
		for(i=0;i<n;++i){
			for(j=i;j<n;++j){
				arr[i][j].d = INT_MAX;
			}
		}
		*/
		
		for(i=0;i<n;++i){
			cin >> arr[i][i].a;
			//scanf("%d", &arr[i][i].a);
			arr[i][i].d = 0;
		}
		
		
		for(i=1; i<n; ++i){
			for(j=0;j<n-i;++j){
				y = i+j;
				x = j;
				arr[x][y].a = (arr[x][x].a + arr[x+1][y].a)%100;
				arr[x][y].d = 10000000;
				for(k=x; k<y; ++k){
					temp = arr[x][k].a * arr[k+1][y].a + (arr[x][k].d + arr[k+1][y].d);
					if(temp < arr[x][y].d){
						arr[x][y].d = temp;
					}
				}
			}
		}
		cout << arr[0][n-1].d << endl;
		//printf("%d\n",arr[0][n-1].d);// << endl;
	}
	
	return 0;
}