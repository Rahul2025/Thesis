// filename :: q1_tim.cpp


#include <iostream>
#include <vector>
#include <map>
#include <math.h> 
using namespace std;


map <unsigned long int, unsigned long int> value;

int maxCoins( int n ) // recursive solution ( obviously does not work )
{
    if( n == 0 )
        return 0;
    
    n = max( n , maxCoins(n/2)+ maxCoins(n/3) + maxCoins (n/4) );
    
    return n;
}


int maxDPCoins ( unsigned long int n ) // dynamic programming ( takes too much memory, try 1000000000 )
{
    vector <unsigned long int> dp ( n + 1 );
    
    dp[0] = 0;
    dp[1] = 1;
    
    for (unsigned long int  i = 2; i <= n; i++) {
        dp[i] = max( i, dp[ i/2 ] + dp[ i/3] + dp[i/4] );
    }
    
    return dp[n];
}

unsigned long int maxUsingMap( unsigned long int n )
{
    if (value[n] != 0) {
        return value[n];
    }
    if (n < 12) {
        return n;
    }
    
    unsigned long int temp = maxUsingMap( floor(n/2) ) + maxUsingMap( floor(n/3) ) + maxUsingMap(floor(n/4));
    if (temp < n) {
        value[n] = n;
    }
    else
        value[n] = temp;
    
    return value[n];
}



int main()
{
    unsigned long int n;
    
    while (cin >> n) {
        cout << maxUsingMap( n ) << endl;

    }
    
    return 0;
}