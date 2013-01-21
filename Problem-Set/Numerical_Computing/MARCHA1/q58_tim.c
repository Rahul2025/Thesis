# include <stdio.h>

//# include <conio.h>



int fn ( int *, int ) ;

void qsort ( int * a, int n )

{

	int i, j, t ;

	for ( i = 0 ; i < n-1 ; i++ )

		for ( j = i+1 ; j < n ; j++ )

			if ( a[i] < a[j] )

			{

				t = a[i] ;

				a[i] = a[j] ;

				a[j] = t ;

			}

}

			



int main ( )

{

    int t, n, m, a[21], i ;

    scanf ( "%d", &t ) ;

    while ( t-- ) 

    {

          scanf ( "%d%d", &n, &m ) ;

          if ( n == 0 )

             printf ( "No\n" ) ;

          for ( i = 0 ; i < n ; i++ )

              scanf ( "%d", a+i ) ;

          qsort ( a, n ) ;

/*	for ( i = 0 ; i < n ; i++ )

		printf ( "%d\n", a[i] ) ;*/

          a[n] = -1 ;

          if ( fn ( a, m ) )

             printf ( "Yes\n" ) ;

          else

             printf ( "No\n" ) ;

    }

//    getch ( ) ;

    return 0 ;

}



int fn ( int *a, int m )

{

    int i ;

    if ( *a == -1 )

       return 0 ;

    for ( ; *a != -1 ; a++ )

    {

        if ( *a == m )

           return 1 ;

        if ( *a < m )

           return (fn (a+1, m-(*a)) || fn (a+1, m));

    }

    return 0 ;

}