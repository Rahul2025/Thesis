#include <stdio.h>

int scan(){
    int t=0;
    char c;
    c=getchar_unlocked();
    while(c<'0' || c>'9')
        c=getchar_unlocked();
    while(c>='0' && c<='9'){
        t=(t<<3)+(t<<1)+c-'0';
        c=getchar_unlocked();
    }
    return(t);
}

int main(){
    int t;
    t=scan();
    while(t--){
        int n,i,count=0,min=2147483647,var;
        n=scan();
        for(i=0;i<n;i++){
            var=scan();
            if(var<=min){
                count++;
                min=var;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}