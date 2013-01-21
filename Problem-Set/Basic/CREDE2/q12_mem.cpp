#include <iostream>

using namespace std;

int digitsum(int x)
{
	int sum = x;
	while ( x > 0 ) {
		sum = sum + x%10;
		x = x/10;
	}
	return sum;
}

int main()
{
	int n,i,x;
	cin >> n;

	while ( n-- ) {
		cin >> x;
		for ( i = 0; i <= x; i++ ) {
			if ( digitsum(i) == x ) {
				cout << i << endl;
				goto a;
			}
		}
		cout << "NONE" << endl;
		a: {}
	}
	return 0;
}

		
	