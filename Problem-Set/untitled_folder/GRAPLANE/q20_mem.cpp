#include <cstdio>
#include <cstring>

int sx[] = {+1,+1,-1,-1};
int sy[] = {+1,-1,+1,-1};

int n, m, pr;
int p[4];
int a[32][32], nei[32];
int sol[1<<18];

int X[32], Y[32];

int son[1<<18];

int cntBit( int ma )
{
	int r = 0;
	while ( ma > 0 )
	{
		if ( ma&1 ) r++;
		ma = ma / 2;
	}
	return r;
}

int nex( int us )
{
	//printf( "nex %d\n", us );
	if ( us == 1 ) return 0;
	int lb = (us&(-us));
	if ( lb > 1 )
	{
		return us + lb/2 - lb;
	}
	int k = nex( us/2 )*2;
	if ( k == 0 ) return 0;
	lb = (k&(-k));
	return k + lb/2;
}

int solve( int ma )
{
//	printf( "inSOLVE %d\n", ma );
	if ( sol[ma] != -1 ) return sol[ma];
	
	int i, k, bi;
	int be = -1, nm;
	int x[19];
	//bool us[19];
	int us;
	bi = 0;
	for ( i = 0; i < n; i++ )
	{
		if ( (ma&(1<<i)) )
			x[bi++] = (1<<i);
	}
	
	if ( bi <= p[3] )
	{
		k = 0;
		for ( i = 0; i < n; i++ )
		{
			if ( (ma&(1<<i)) )
			{
				k = k + cntBit(ma&nei[i]);
			}
		}
		sol[ma] = k/2;
		son[ma] = -1;
//		printf( "SOLVE %d %d\n", ma, sol[ma] );
		return sol[ma];
	}
	
//	memset( us, 0, sizeof( us ) );
	us = 0;
	for ( i = bi-1; i >= bi-bi/2; i-- )
		us = (us|(1<<i));
	
	do
	{
		nm = 0;
		for ( i = 0; i < bi; i++ )
		{
			if ( us&(1<<i) )
			{
				nm = (nm|x[i]);
/*				while ( ( sk < i ) || ( (ma&(1<<j)) == 0 ) )
				{
					if ( (ma&(1<<j)) )
						sk++;
					j++;
				}
				nm = (nm|(1<<j));*/
			}
		}
		
		i = solve( nm ) + solve( ma^nm );
		if ( i > be )
		{
			be = i;
			son[ma] = nm;
		}
		us = nex( us );
	}
	while ( us );
	sol[ma] = be;
	
//	printf( "SOLVE %d %d\n", ma, sol[ma] );
	return sol[ma];
}

void printme( int ma )
{
	int i;
//	printf( "PRINTME !! %d %d\n", ma, son[ma] );
	if ( son[ma] == -1 )
	{
		for ( i = 0; i < 18; i++ )
		{
			if ( ma&(1<<i) )
			{
				X[i] = (i+1)*sx[pr];
				Y[i] = (i+1)*sy[pr];
//				printf( "%d %d\n", (i+1)*sx[pr], (i+1)*sy[pr] );
			}
		}
		pr++;
	}
	else
	{
		printme( son[ma] );
		printme( ma^son[ma] );
	}
}

int main()
{
	int i, j, k, bma, bs, mx;
	int t, T;
	scanf( "%d", &T );
	for ( t = 0; t < T; ++t )
	{
		scanf( "%d %d", &n, &m );
		memset( a, 0, sizeof( a ) );
		memset( nei, 0, sizeof( nei ) );
		for ( i = 1; i <= m; i++ )
		{
			scanf( "%d %d", &j, &k );
			j--; k--;
			a[j][k] = 1;
			a[k][j] = 1;
			nei[j] = (nei[j]|(1<<k));
			nei[k] = (nei[k]|(1<<j));
		}
		memset( sol, -1, sizeof( sol ) );
		memset( son, -1, sizeof( son ) );
		k = n/4; j = 0; i = 3;
		while ( j+(i+1)*k < n )
		{
			p[i] = k+1;
			j = j + k+1;
			i--;
		}
		while ( i >= 0 )
		{
			p[i] = k;
			i--;
		}
		if ( p[0] == 0 )
		{
			k = 0;
			for ( i = 0; i < n; i++ )
			{
				for ( j = i+1; j < n; j++ )
					k = k + a[i][j];
			}
			printf( "%d\n", k );
			if ( n >= 1 )
				printf( "1 1\n" );
			if ( n >= 2 )
				printf( "1 -1\n" );
			if ( n >= 3 )
				printf( "-1 1\n" );
			if ( n >= 4 )
				printf( "-1 -1\n" );
			printf( "\n" );
			continue;
		}
//		printf( "%d %d %d %d\n", p[0], p[1], p[2], p[3] );
		//return 0;
		
		bma = -1; bs = -1;
		mx = (1<<n);
		for ( i = 0; i < mx; i++ )
		{
			if ( cntBit( i ) == n/2 )
			{
				k = solve( i ) + solve( mx-1-i );
				if ( k > bs )
				{
					bs = k;
					bma = i;
				}
			}
		}
		printf( "%d\n", m-bs );
		
		pr = 0;
		printme( bma );
		printme( mx-1-bma );
		for ( i = 0; i < n; i++ )
		{
			printf( "%d %d\n", X[i], Y[i] );
		}
		if ( t < T-1 ) printf( "\n" );
	}
	return 0;
}


/*bool ok( int le, int k, int us[] )
{
	int i, r;
	for ( i = le-k; i < le; i++ )
	{
		r = r + us[i];
	}
	if ( r == k ) return 0;
	return 1;
}*/

/*bool nex( int le, bool us[] )
{
	int i, j = 0;
	for ( i = le-1; i >= 0; i-- )
	{
		if ( ( us[i] == 1 ) && ( i+j == le-1 ) )
		{
			j++;
			us[i] = 0;
		}
		else if ( ( us[i] == 1 ) && ( i+j < le-1 ) )
		{
			us[i] = 0;
			j++;
			for ( int l = i+1; l <= i+j; l++ )
				us[l] = 1;
			return 1;
		}
	}
	return 0;
}*/