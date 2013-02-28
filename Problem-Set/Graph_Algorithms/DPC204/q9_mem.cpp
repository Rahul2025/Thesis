#include<stdio.h>
#include<time.h>
#include<math.h>
int main(){
        #ifdef raj
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("log.txt", "w", stderr);
        #endif
        unsigned long long a,b,t;
        int t1=1,t2=1,count;
        double phi = (1 + sqrt(5)) / 2;
        scanf("%llu %llu",&a,&b);
        while(a && b){
                count=0;
                for(int i=1;i<=300;i++){
                    t=(((pow(phi,i))/ sqrt(5))+0.5);
                    //printf("%llu\n",t);
                    if(t>b)
                    break;
                    if(t>=a)
                    count++;

                }
                printf("%d\n",count);
                scanf("%llu %llu",&a,&b);
        }
        return 0;
}