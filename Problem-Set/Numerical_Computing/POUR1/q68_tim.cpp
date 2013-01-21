#include<iostream>

using namespace std;

int gcd(int n1, int n2)
{
    int rem;
    while(n2)
    {
        rem=n1%n2;
        n1=n2;
        n2=rem;
    }
    return n1;
}

int main()
{
int test,a,b,c,temp,count,ta,tb,flag;
cin >> test;
while(test--)
{
    cin >> a >> b >> c;
    count=0;

    if(a<b)
    {
        temp=a;
        a=b;
        b=temp;
    }


    if(c>a || c%gcd(a,b)!=0)
    {
        cout << "-1\n";
        continue;
    }

    if(c==a || c==b)
    {
        cout << "1\n";
        continue;
    }

    flag=1;
    ta=0;
    tb=0;
    while(flag)
    {
        if(tb==0)
        {
            tb=b;
            count++;
        }
        else if(ta==a)
        {
            ta=0;
            count++;
        }
        else
        {
            if(a-ta>tb)
            {
                ta=ta+tb;
                tb=0;
                count++;
                if(ta==c || (a-ta)==c)
                {
                cout << count << endl;
                flag=0;
                }
            }
            else
            {
                tb=tb-a+ta;
                ta=a;
                count++;
                if(tb==c)
                {
                    cout << count << endl;
                    flag=0;
                }
            }
        }
    }


}

    return 0;
}