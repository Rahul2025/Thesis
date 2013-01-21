#include<stdio.h>
#define getcx getchar_unlocked
void inp( int * n )//fast input function
{
     *n=0;
     int ch=getcx();
     int sign=1;
     while( ch < '0' || ch > '9' )
     {
            if(ch=='-')
                 sign=-1; 
                 ch=getcx();
                 }
     while( ch >= '0' && ch <= '9' )
     {
     *n = ((*n)<<3)+((*n)<<1) + ch-'0', ch=getcx();
     }
     *n=(*n)*sign;
     }
int main()
{
    int t,n,c,a,b;
    inp(&t);
    while(t-->0)
    {
                inp(&n);
                    c=1;
                    if(n>=1)
                            inp(&a);
                    for(int i=1;i<n;i++)
                          {  inp(&b);
                            if(a>=b)
                            {
                                   a=b;
                                   c++;
                                           }
                                           }		
                    printf("%d\n",c);                    
                }
    return 0;
    }