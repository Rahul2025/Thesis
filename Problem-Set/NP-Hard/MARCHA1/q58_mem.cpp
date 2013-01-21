#include <stdio.h>
#include <algorithm>
using namespace std;

int main ()
{
    int dataset;
    scanf ("%d", &dataset);

    int a [20];

    while ( dataset-- ) {
        int n;
        int m;
        scanf ("%d %d", &n, &m);

        for ( int i = 0; i < n; i++ )
            scanf ("%d", &a [i]);

        int binary [20] = {0};
        bool flag = true;

        for ( int i = 0; i < n; i++ ) {
            binary [0] = 1;
            sort (binary, binary + n);
            do {
                int sum = 0;
                for ( int j = 0; j < n; j++ ) {
                    if ( binary [j] )
                        sum += a [j];
                }

                if ( sum == m ) {
                    printf ("Yes\n");
                    flag = false;
                    i = n;
                    break;
                }

            } while ( next_permutation (binary, binary + n) );
        }

        if ( flag )
            printf ("No\n");
    }

    return 0;
}