#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>
int main(){
    int t;
    scanf("%d",&t);
    while (t>0) {
        int n,x1,y1,x2,y2,x3,y3;
        double a,b,c;
        scanf("%d %d %d %d %d %d %d",&n,&x1,&y1,&x2,&y2,&x3,&y3);
        a=sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
        b=sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));
        c=sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));
        if(c<=b && a<=b){
            if(c<=n && a<=n)
                printf("yes\n");
            else printf("no\n");
         }
        else if(a<=c && b<=c){
            if(a<=n && b<=n)
                printf("yes\n");
            else printf("no\n");
        }
        else if(c<=a && b<=a){
            if(b<=n && c<=n)
                printf("yes\n");
            else printf("no\n");
        }
        else printf("no\n");
        t--;
    }
}