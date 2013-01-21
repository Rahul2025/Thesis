#include<stdio.h>
int main()
{
  int arr[1005],arr1[100005],arr2[1005],i,j,k=1,n,count=0,m,count1;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
   scanf("%d",&arr[i]);
   //arr1[i]=arr[i];
}
  for(i=1;i<=n;)
  {
   count1=0;
   j=arr[i];
   arr2[i]=-1;
   arr1[k]=i;
   while(arr2[j]!=-1)
  {
        k++;
        arr2[j]=-1;
        arr1[k]=j;
        j=arr[j];
        //k++;
  }
   arr1[++k]=i;
   k++;
   count++;
   for(j=1;j<=n;j++){
   if(arr2[j]==0){
   i=j;break;}}
   for(j=1;j<=n;j++){
   if(arr2[j]==-1){
   count1++;}}
  if(count1==n)
  break;
  }
  printf("%d\n",count);
  for(i=1;i<=k-2;)
  {
   j=arr1[i];
   printf("%d ",j);
   i++;
   while(arr1[i]!=j){
    printf("%d ",arr1[i]);
    i++;
   }
   printf("%d\n",arr1[i]);i++;
  }
return 0;
}