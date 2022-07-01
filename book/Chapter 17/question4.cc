#include <bits/stdc++.h>
#include <bitset>

using namespace std;

int max(int a, int b)
{
    std::bitset<32> a_bits(a);
    std::bitset<32> b_bits(b);
    std::bitset<32> a_b_bits(a-b);
    std::bitset<32> a_b_shift_bits((a-b) >> sizeof(int));
    std::bitset<32> res_bits(a-((a-b)&((a-b)>>sizeof(int))));
    cout << "a:          " << a_bits << endl;
    cout << "b:          " << b_bits << endl;
    cout << "a-b         " << a_b_bits << endl;
    cout << "(a-b) >> 32 " << a_b_shift_bits << endl;
    cout << "res         " << res_bits << endl;
    return a-((a-b)&((a-b)>>sizeof(int)));
}


