#include <bits/stdc++.h>

using namespace std;

long fact(int n)
{
    long res = n;
    for (int i = n - 1; i > 0; i--)
    {
        res *= i;
    }
    
    return res;
}

int trailing_zeros(int n)
{
    long f = fact(n);
    int res = 0;
    while (f > 0 && f % 10 == 0)
    {
        res++;
        f /= 10;
    }

    return res;
}

int main()
{
    int n = 20;
    cout << "Factorial: " << fact(n) << endl;
    cout << "Trailing zeros: " << trailing_zeros(n) << endl;
}