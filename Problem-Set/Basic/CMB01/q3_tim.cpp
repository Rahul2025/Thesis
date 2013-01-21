#include <iostream>
#include <cmath>

using namespace std;

int rev(int num)
{
    int tempnum = num;
    int retval = 0;
    int count = 0;
    while (tempnum > 0)
    {
        tempnum /= 10;
        count++;
    }
    for (int j = count; j > 0; j--)
    {
        retval += (num % 10) * pow(10, j-1);
        num /= 10;
    }
    return retval;
}

int main(void)
{
    int testcases, x, y;
    cin >> testcases;
    for (int i = 1; i <= testcases; i++)
    {
        cin >> x >> y;
        cout << rev(rev(x) + rev(y)) << endl;
    }
}