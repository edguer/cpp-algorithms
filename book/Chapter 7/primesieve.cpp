#include <bits/stdc++.h>
#include <math.h>

using namespace std;

void list_primes(int value)
{
    bool primes[32000];
    fill_n(primes, 32000, true);

    int prime = 2;
    while (prime <= sqrt(value))
    {
        // cross
        for (int i = pow(prime, 2); i < value; i += prime)
        {
            primes[i] = false;
        }
        do
        {
            prime++;
        } while (prime < value && !primes[prime]);
    }

    for (int i = 0; i <= value; i++)
    {
        if (primes[i])
        {
            cout << i << " is prime" << endl;
        }
    }
}

int main()
{
    list_primes(50);
}