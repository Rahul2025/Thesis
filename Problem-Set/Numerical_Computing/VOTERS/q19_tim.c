#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
int fastread()
{
int input;
char c=0;
while (c<33) c=getchar_unlocked();
input=0;
while (c>33)
{
input=input*10+c-'0';
c=getchar_unlocked();
}
return input;
}
int int_cmp(const void *a, const void *b) 
{ 
    const int *ia = (const int *)a; // casting pointer types 
    const int *ib = (const int *)b;
    return *ia  - *ib; 
	/* integer comparison: returns negative if b > a 
	and positive if a > b */ 
}
int main()
{
int n1=fastread();
int n2=fastread();
int n3=fastread();
int i,a[50000],b[50000],c[50000],d[50000],j,k;
for(i=0;i<n1;i++)
 	a[i]=fastread();
for(i=0;i<n2;i++)
	b[i]=fastread();
for(i=0;i<n3;i++)
	c[i]=fastread();
   j=0;
   k=0;
for(i=0;i<n1;i++)
{
	while(j<n2 && a[i]>=b[j])
   {
   if(a[i]==b[j] && a[i]!=0)
   {
    d[k++]=a[i];
    //printf("%d ",d[k-1]);
    a[i]=b[j]=0;
    j++;
    break;
   }
     else j++;
   }
}
j=0;
for(i=0;i<n2;i++)
{
	while(j<n3 && b[i]>=c[j])
   {
   if(b[i]==c[j] && b[i]!=0 )
   {
    d[k++]=b[i];
    //printf("%d ",d[k-1]);
    b[i]=c[j]=0;
    j++;
    break;
   }
     else j++;
   }
}
j=0;
for(i=0;i<n3;i++)
{
	while(j<n1 && c[i]>=a[j])
   {
   if(c[i]==a[j] && c[i]!=0)
   {
    d[k++]=c[i];
    //printf("%d ",d[k-1]);
    c[i]=a[j]=0;
    j++;
    break;
   }
     else j++;
   }
}
printf("%d\n",k);
qsort(d, k, sizeof(int), int_cmp );
for(i=0;i<k;i++)
printf("%d\n",d[i]);

//getch();
return 0;
}