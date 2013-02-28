#include <stdio.h>

#define A 11
#define B  6

int
istrlen (char* a)
{
    int i = 0;
    while (*a++) {
        i++;
    }
    return i;
}

int
is_substring (char* a, char* b)
{
    int la = istrlen (a), lb = istrlen(b);
    int j = 0, flag = -1, i = 0, st = 0;
    for (i = 0; i <= la - lb; i++) {
        flag = 1, j = 0, st = i;
        while (b[j]) {
            if (a[st] != b[j]) {
                flag = 0;
                break;
            }
            st++, j++;
        }
        if (flag == 1) {
            return flag;
        }
    }
    return 0;
}

int
main()
{
    int t = 0;
    scanf ("%d", &t);
    while (t--) {
        char a[A] = {'\0'};
        char b[B] = {'\0'};
        scanf ("%s %s", a, b);
        printf ("%d\n", is_substring(a, b));
    }
    return 0;
}
