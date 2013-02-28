#include<stdio.h>
int main(){
int T,N;
for(scanf("%d",&T);T>0;T--){
scanf("%d",&N);
if(N%4 == 1)
printf("ALICE\n");
else
printf("BOB\n");
}
}