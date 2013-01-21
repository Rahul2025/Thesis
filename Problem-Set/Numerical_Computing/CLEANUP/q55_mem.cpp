#include <stdio.h>


int main() {
    int N, n, m, t;
    int chores[1010];
    int i, j;

    scanf("%d", &N);

    while(N--) {
        scanf("%d %d", &n, &m);

        for (i=1; i<=n; i++) chores[i] = 0;
        for (i=0; i<m; i++) {
            scanf("%d", &t);
            chores[t] = 1;
        }

        t = 0;
        for (i=1; i<=n; i++) {
            if(!chores[i]) {
                if (t%2==0 && t==0) printf("%d", i);
                else if (t%2==0) printf(" %d", i);
                t++;
            }
        } printf("\n");
        t = 0;
        for (i=1; i<=n; i++) {
            if(!chores[i]) {
                if (t%2!=0 && t==1) printf("%d", i);
                else if (t%2!=0) printf(" %d", i);
                t++;
            }
        } printf("\n");
    }
}