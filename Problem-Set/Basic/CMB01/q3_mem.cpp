#include<stdio.h>
long int rev(long int);
int main(){
    long int n,n1,n2,r1,r2,sum;
    scanf("%ld",&n);
    while(n--){
        scanf("%ld %ld",&n1,&n2);
        /*while(n1%10)
            n1=n1/10;
        while(n2%10)
            n2=n2/10;
            */
        r1=rev(n1);
        r2=rev(n2);
        sum=r1+r2;
        sum=rev(sum);
        printf("%ld\n",sum);
    }

    return 0;

}
long int rev(long int n){
    long int r=0;
    while(n>0){
        r=r*10+n%10;
        n=n/10;
    }
    return r;
}