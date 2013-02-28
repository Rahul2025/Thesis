#include "stdio.h"
int rev(int n) {
int b, sum=0;
while (n>0) {
b=n%10;
n=n/10;
sum=sum*10+b;
}
return sum;
}
int main() {
int n, revn, s=0, t, i;
scanf("%d", &t);
for (i=0;i<t;i++) {
scanf("%d", &n);
s=0;
revn=rev(n);
while (n!=revn && s<=5) {
s++;
// printf("%d : %d + %d", s, n, revn);
n=n+revn;
revn=rev(n);
// printf(" = %d\n", n);
}
printf("%d %d\n",s, revn);
}
return 0;
}