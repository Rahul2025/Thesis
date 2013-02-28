#include<stdio.h>
#include<string.h>

int a[65536];
void create(){
     int t=32768,i=1,check=32768;
     a[0]=0;
     a[1]=t;
     for(i=2;i<65536;i++){
                          check=32768;
                          while(t&check){t^=check;check>>=1;}
                          t|=check;
                          a[i]=t;
                          }
}
int main(){
    char c[65537],b[65537];
    int k,i,t,l;
    create();
    scanf("%d",&t);
    while(t--){
               scanf("%d %s",&k,c);
               l=strlen(c);
               for(i=0;i<l;i++){
                                        b[a[i]>>(16-k)]=c[i];
                                        }
               b[i]=0;
               printf("%s\n",b);
               }
                                        
    return 0;
}

     