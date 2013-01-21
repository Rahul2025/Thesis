#include<stdio.h>

 int getno()
{
    int x=0;
    char c;
    c=getc(stdin);
    for(;(c==' ')||(c=='\n');c=getc(stdin));
    
    for(;((c>47)&&(c<59));c=getc(stdin))
     x=(x<<3)+(x<<1)+(c-48);
    return(x);
}
int main()
{
    int tc,i,j,k,n,t;
    int arr[101][3];
    double low,high,mid,val[101],ans,p;
    tc=getno();
    
    while(tc--)
    {      n=getno();
           i=0;
           for(i=0;i<n;i++)
           {        arr[i][0]=getno();
                     if(arr[i][0])
                     { arr[i][1]=getno();
                       arr[i][2]=getno();
                     }
           }
                     low=0.0;
                     high=1.0;
                               
                             mid=(high+low)/2;
                                  
                     for(t=0;t<55;t++)
                     {
                              j=0;
                               while(j<n)
                               {
                                         if(arr[j][0]==0)
                                         {
                                                       val[j]=mid;
                                         }
                                         else if(arr[j][0]==1)
                                         {
                                              val[j]=1-(1-val[arr[j][1]-1])*(1-val[arr[j][2]-1]);
                                         }
                                         else if(arr[j][0]==2)
                                         {
                                             val[j]=val[arr[j][1]-1]*val[arr[j][2]-1];
                                         }
                                         j++;
                               }
                               ans=val[n-1];
                               if(ans==(0.5))
                               {           break;
                               }
                            if(ans<0.5)                               
                               {
                                    low=mid;
                                    mid=(high+low)/2;
                               }
                               else
                               {
                                   high=mid;
                                   mid=(high+low)/2;
                               }
                            
                     }
                     printf("%.5lf\n",mid);
           
    }
    
    return 0;
    }