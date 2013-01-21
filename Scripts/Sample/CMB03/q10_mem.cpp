#include<stdio.h>
#include<string.h>
int main(){
    char a[11],b[10];
    int n;
    scanf("%d",&n);
    while(n--){
    scanf("%s %s",a,b);

        printf(strstr(a,b) ? "1\n" : "0\n");
    }
    return 0;
}