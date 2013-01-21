#include<stdio.h>
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
int counter=0,max,min,l=0,i,j,n,arr[2][100],a[1000];
scanf("%d",&n);
for(i=0; i<2; i++)
{
for(j=0; j<n; j++)
{
scanf("%d",&arr[i][j]);
}
}

max=arr[0][0];
min=arr[0][0];
for(i=0; i<2; i++)
{
for(j=0; j<n; j++)
{
if(arr[i][j]>max){max=arr[i][j];}
else if(arr[i][j]<min){min=arr[i][j];}
}
}


for(i=min; i<max; i++)
{
counter=0;

for(j=0; j<n; j++)
{
if(i>=arr[0][j]&&i<arr[1][j]){counter=counter+1;}
}
a[l]=counter;
l++;
}
max=a[0];
for(i=0; i<l; i++)
{
if(a[i]>max){max=a[i];}
}
printf("%d\n",max);
}
return 0;
}