#include <bits/stdc++.h>
#include <math.h>

using namespace std;

bool prime(int value)
{
    int sqrt_value = sqrt(value);
    for (int i = 2; i <= sqrt_value; i++)
    {
        if (value % i == 0) return false;
    }
    
    return true;
}

int main()
{
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    for (int i = 0; i < 100; i++)
    {
        cout << i << " is prime? " << prime(i) << endl;
    }
}