#include<stdio.h>
#include<string.h>
int main()
{
int t,i,j,l,f,fp,mid;
char a[1000010];
scanf("%d",&t);gets(a);
for(i=0;i<t;i++)
{
gets(a);
l=strlen(a);f=0;
for(j=0;j<l;j++)
{
if(a[j]!='9')
{f=1;break;}
}
if(f==0)
{
a[0]='1';
for(j=1;j<l;j++)
a[j]='0';
a[j]='1';
a[j+1]='\0';
}
else
{
fp=0;
for(j=0;j<l/2;j++)
{
if(a[j]<a[l-j-1])
fp=-1;
if(a[j]>a[l-j-1])
fp=1;
a[l-j-1]=a[j];
}
if(l%2==0)
mid=l/2-1;
else
mid=l/2;
if(fp==-1 || fp==0)
{
j=0;
while(a[mid-j]=='9')
{
a[mid-j]='0';
a[l-mid+j-1]='0';
j++;
}
a[mid-j]++;
a[l-mid+j-1]=a[mid-j];
}
}
printf("%s\n",a);
}
return 0;
}