#include<iostream.h>
int cal(int *a)
{
 int temp;
 for(int i=0;i<5;++i)
  {
   for(int j=0;j<5;++j)
   {
    if(a[j]>a[i])
    {
     temp=a[j];
     a[j]=a[i];
     a[i]=temp;
    }
   }
  }

 if((a[4]-a[3]==1)&&(a[3]-a[2]==1)&&(a[2]-a[1]==1)&&(a[1]-a[0]==1))
 return 1;
 else return 0;
}

int main()
{
char num[6],type[6];
int t,j,arr[5];
cin>>t;

for(int i=0;i<t;++i)
{

 for(j=0;j<5;++j)
 {
  cin>>num[j]>>type[j];

  switch(num[j])
  {
   case 'A':arr[j]=1;break;
   case 'K':arr[j]=13;break;
   case 'Q':arr[j]=12;break;
   case 'J':arr[j]=11;break;
   case 'T':arr[j]=10;break;
   default:arr[j]=(num[j]-48);
   }
  }
 int count,c[5]={0,0,0,0,0};
 for(int p=0;p<5;++p)
 {
   count=0;
   for(int k=0;k<5;++k)
  {
   if(arr[p]==arr[k])
   count++;
  }
  c[p]=count-1;
 }

if((type[0]==type[1])&&(type[1]==type[2])&&(type[2]==type[3])&&(type[3]==type[4]))
{
 if(arr[0]+arr[1]+arr[2]+arr[3]+arr[4]==47)
 cout<<"royal flush"<<endl;
 else
 if(cal(arr)==1)
 cout<<"straight flush"<<endl;
 else
 cout<<"flush"<<endl;
}
 else
 if((c[0]==3)||(c[1]==3)||(c[2]==3))
 cout<<"four of a kind"<<endl;
 else
 if(((c[0]==2)||(c[0]==1))&&((c[1]==2)||(c[1]==1))&&((c[2]==2)||(c[2]==1))&&(c[3]==2)||(c[3]==1))
 cout<<"full house"<<endl;
 else
 if(cal(arr)==1)
 cout<<"straight"<<endl;
 else
 if((c[0]==2)||(c[1]==2)||(c[2]==2)||(c[3]==2))
 cout<<"three of a kind"<<endl;
 else
 if((c[0]+c[1]+c[2]+c[3]+c[4])==4)
 cout<<"two pairs"<<endl;
 else
 if((c[0]==1)||(c[1]==1)||(c[2]==1)||(c[3]==1))
 cout<<"pair"<<endl;
 else
 cout<<"high card"<<endl;
}
return 0;
}