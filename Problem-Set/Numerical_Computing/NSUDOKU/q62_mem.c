#include <stdio.h>
#include <string.h>

typedef unsigned long  ulong;
typedef unsigned short ushort;

/* 1224630.25 pts */
ushort strategy1(ulong r, ulong c, ulong N, ulong N2)
{
    return 1;
}

/*  392089.50 pts */
ushort strategy2(ulong r, ulong c, ulong N, ulong N2)
{
    return (r / N + (r % N) * N + c) % N2 + 1;
}

/*  ?? pts */
ushort strategy3(ulong r, ulong c, ulong N, ulong N2)
{
    ushort V = (r / N + r * N + c) % N2;
    if (V == 0) return N2; else return V;
}

int main()
{
    ulong N, N2, K, k, r, c, X, Y, D;
    ushort G[900][900];

    memset(G, 0, sizeof(G));
    scanf("%lu %lu\n", &N, &K);
    N2 = N * N;

    for (k = 0; k < K; k++)
    {
        scanf("%lu %lu %lu\n", &X, &Y, &D);
        G[X - 1][Y - 1] = D;
    }

    for (r = 0; r < N2; r++)
    for (c = 0; c < N2; c++)
    if  (G[r][c] == 0)
    G[r][c] = strategy3(r, c, N, N2);

    for (r = 0; r < N2; r++)
    {
        for (c = 0; c < N2; c++)
        printf("%u ", G[r][c]);
        printf("\n");
    }

    return 0;
}