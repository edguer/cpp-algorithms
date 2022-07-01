#include <bits/stdc++.h>
#include "utils.hpp"

using namespace std;

bool IsSubstring(const char * full_str, const char * sub_str, unsigned short int sub_str_len)
{
    unsigned short int hits = 0;
    while (*full_str)
    {
        cout << "f " << *full_str << " s " << *sub_str << endl;
        if (*full_str == *sub_str)
        {
            hits++, sub_str++;
            if (hits == sub_str_len)
            {
                return true;
            }
        }
        else if (hits > 0)
        {
            sub_str = sub_str - hits;
            hits = 0;
        }
        full_str++;
    }

    return false;
}

int main()
{
    string a = "Eduardo da Rocha", b = "a RochaEduardo d";
    string concat = a + a;
    cout << IsSubstring(concat.c_str(), b.c_str(), b.length());
}