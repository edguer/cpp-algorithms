#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void swap2(int *a, int *b)
{
    // a 4 b 9
    *a = *a - *b; // a -5
    *b = *a + *b; // b 9 - 5 => 4
    *a = *b - *a; // a 4 -(-5) => 9 
}

int main()
{
    int a = 4, b = 40;
    swap2(&a, &b);
    cout << "a " << a << " b " << b << endl;
}