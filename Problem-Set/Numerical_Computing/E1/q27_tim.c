#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max( a, b ) ( (a) > (b) ? (a) : (b) )

int R[ 1002 ][ 1002 ];

int main( int argc, char **argv ){
	int TC, N, i, j, k;
	char B[ 1002 ][ 1002 ];
	
	scanf( "%d", &TC );
	
	while( TC-- ){
		scanf( "%d\n", &N );
		
		for( i = 0; i ^ N; i++ )
			gets( B[ i ] );
		
		for( j = N; j--; ){
			for( i = 0; i ^ N; i++ ){
				k = 0;
				if( ( j + 1 ) < N && ( i - 2 ) >= 0 ) k = max( k, R[ i - 2 ][ j + 1 ] );
				if( ( j + 2 ) < N && ( i - 1 ) >= 0 ) k = max( k, R[ i - 1 ][ j + 2 ] );
				if( ( j + 2 ) < N && ( i + 1 ) < N ) k = max( k, R[ i + 1 ][ j + 2 ] );
				if( ( j + 1 ) < N && ( i + 2 ) < N ) k = max( k, R[ i + 2 ][ j + 1 ] );
				
				if( B[ i ][ j ] == 'K' ){
					printf( "%d\n", k );
					break;
				}
				
				R[ i ][ j ] = k + ( B[ i ][ j ] == 'P' );
			}
			
			if( i < N ) break;
		}

	}

	return 0;
}