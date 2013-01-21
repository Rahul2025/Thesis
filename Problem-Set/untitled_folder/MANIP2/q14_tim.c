#include<stdio.h>
#define SIZE 8192
long long int arr[SIZE];
long long int power(int x,int y){
long long int t;
if(y==0)
   return 1;
if(y%2==0)
{t=power(x,y/2);
   return t*t;}
else
{t=power(x,y/2);
 return x*t*t;}
}
void compute(){
int count=1,i,temp,index;
for(i=1;i<8192;i<<=1)
   arr[i]=power(5,count++);
for(i=3;i<=8000;i++){
count=-1;
temp=i;
while(temp!=0){
count++;temp/=2;}
index=1<<count;
     arr[i]=arr[index]+arr[i-index];
}
}
int main(){
int t,n;
compute();
scanf("%d",&t);
while(t--){
scanf("%d",&n);
printf("%d\n",arr[n]);
}
return 0;
}