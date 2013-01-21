#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
void mak(unsigned array[],  unsigned size);
int max(int ,int ,int);
int main()
{
int n1,n2,n3,n,*a,*b,i,l,r,j=0,num,count=0;
scanf("%d %d %d",&n1,&n2,&n3);
n=n1+n2+n3;
a=(int *)malloc(n*sizeof(int));
r=max(n1,n2,n3);
//printf("%d",r);
b=(int *)malloc(r*sizeof(int));
for(i=0;i<r;i++)
b[i]=0;
for(i=0;i<n;i++)
scanf("%d",&a[i]);
sort(a,a+n);
i=0;
while(i<n){
 num=a[i];
 if(a[i+1]==num)
 {
 count++;i++;

 continue;
 }
else

 i++;
if(count>0){
b[j++]=num;//printf("%u\n",num);
 count=0;
 }
}
count=0;
for(i=0;i<r&&b[i]!=0;i++)
count++;
printf("%d\n",count);
for(i=0;i<count;i++)
printf("%d\n",b[i]);

    return 0;
}

void mak(unsigned array[], unsigned size){
unsigned i,j ,temp;
for(i=0;i<size;i++)
{
for(j=0;j<(size-i-1);j++)
{
if(array[j]>array[j+1])
{
temp=array[j];
array[j]=array[j+1];
array[j+1]=temp;
}
}
}
}

int max(int m ,int n,int p){

int r ;
r=m>n? m:n;
return r>p? r:p;
}