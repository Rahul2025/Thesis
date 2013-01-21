//#include<iostream>
//using namespace std;
#include<stdio.h>
#include<string.h>



//long long int mod = 1000000007;

/*long long int ncr(int n, int r)
{
    int i;
    long long int m=1;
    if(n<r)
    //return 0;
    m=0;
    else 
    {   for(i=0;i<r;i++)
    m=(m*(n-i))/(i+1);
    //for(i=1;i<=r;i++)
    //m=m/i;
    
    }
    return m;
 }

*/

int main()
{
    char str[10001];
    int y,used[10],a,b,c,d,v,x;
    long long int m,count=0;
    int i,j,k,tc,bm[10],sum;
    //cin>>tc;
    scanf("%d",&tc);
    //fflush(stdin);
    while(tc--)
    {        
             count=0;
             for(i=0;i<10;bm[i++]=0);
               //cin>>str;
               //cout<<str;
               scanf("%s",str);
               //x=strlen(str);
               //for(i=0;i<x;i++)
               //{
                 //              bm[str[i]-'0']++;
               //}
               x=0;
               while(str[x]!='\0')
               {
                             y= str[x]-'0';
                             bm[y]++;
                             x++;
                             //x=getch();
               }         
               //for(i=0;i<10;i++)
               //cout<<bm[i]<<"  bm[i]  "<<endl;      
               for(a=0;a<10;a++)
               {
                                for(b=a;b<11;b++)
                                {
                                                 for(c=b;c<11;c++)
                                                 {
                                                                  for(d=c;d<11;d++)
                                                                  {
                                                                                   //if((((a+b+c+d)%9)==0)&&((a+b+c+d)>0))
                                                                                   /*{if(a==b)&&(b=c)&&(c==d))
                                                                                                            {v=ncr(bm[a],4);
                                                                                                            if(v!=0)
                                                                                                            count++;
                                                                                                            }
                                                                                   else if((dd*/
                                                                            {       for(sum=0,i=0;i<10;used[i++]=0);
                                                                                  if(a<10){sum=sum+a; used[a]++;}
                                                                                  if(b<10){sum=sum+b; used[b]++;}
                                                                                  if(c<10){sum=sum+c; used[c]++;}
                                                                                  if(d<10){sum=sum+d; used[d]++;}
                                                                                   //used[b]++;
                                                                                   //used[c]++;
                                                                                   //used[d]++;
                                                                                   if(((sum%9)==0)&&(sum>0))
                                                                                   
                                                                                  {for(j=0,m=1;j<10;j++)
                                                                                   {
                                                                                                         for(i=0;i<used[j];i++)
                                                                                                          m=(m*(bm[j]-i))/(i+1);
                                                                                                  // if(used[i]!=0)
                                                                                                   //m=m*ncr(bm[i], used[i]);
                                                                                                  // cout<<"return value"<<m;
                                                                                   }
                                                                                   count=count+m;
                                                                                   }
                                                                                   //cout<<count<<endl;
                                                                            }
                                                                  }
                                                 }
                                }
               }     
                                           //count=count + bm[9];
                                                // count= count%mod;
                                                 
               //cout<<count<<endl;
               printf("%lld\n",count%1000000007);
               }
               //system("pause");
               return 0;
               }                                                                                                                  
               
    