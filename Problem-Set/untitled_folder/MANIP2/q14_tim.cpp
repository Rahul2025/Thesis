#include <cstdio>
int main()
{
    int t;
    scanf("%d",&t);
    for (int test=1; test<=t; ++test) {
        unsigned int n;
        scanf("%u", &n);
        unsigned int ans = 0;
        unsigned int power = 5;
        while (n) {
            if (n & 1) {
                ans += power;
            }
            n >>= 1;
            if (n) {
                power *= 5;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}