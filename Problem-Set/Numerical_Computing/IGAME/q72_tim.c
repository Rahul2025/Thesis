#include<stdio.h>
#include<string.h>
#include<math.h>
#define eps 1e-9

int main() {
    int TC; scanf("%d", &TC);
    while(TC--) {
        int m, n, p, q;
        scanf("%d %d %d %d", &m, &n, &p, &q);
        m -= p;
        n -= q;
        if(m > n) {int t = m; m = n; n = t;}
        puts((m - (int)((n - m) * (1 + sqrt(5.0)) / 2 + eps)) ? "Alice" : "Bob");
    }
    return 0;
}