#include <bits/stdc++.h>

using namespace std;

int combinations(string encoded_str, unsigned int last_digit, unsigned short int two_digits,unsigned short int higher_bound)
{
    int count = 0;
    if (last_digit == 0)
        count++;

    if (last_digit < encoded_str.length() - 1)
    {
        unsigned short int index = atoi(encoded_str.substr(last_digit, 2).c_str());
        if (index < higher_bound)
        {
            two_digits++;
            if (two_digits == 1) count++;
        }

        count += combinations(encoded_str, last_digit + 2, two_digits, higher_bound);
        count += combinations(encoded_str, last_digit + 1, 0, higher_bound);
    }
    else if (last_digit == encoded_str.length() - 1 && two_digits > 1)
    {
        count++;
    }

    return count;
}

int main()
{
    char lookup[] = {
        'a',
        'b',
        'c',
        'd',
        'e',
        'f',
        'g',
        'h',
        'i',
        'j',
        'k',
        'l',
        'm',
        'n',
        'o',
        'p',
        'q',
        'r',
        's',
        't',
        'u',
        'v',
        'x',
        'y',
        'z',
        'w'};
    unsigned short int lower_bound = 0, higher_bound = (sizeof(lookup) / sizeof(char)) - 1;

    string encoded_str = "11111"; // aaaa aak ka kk // aaaaa kaaa akaa aaka aaak akk kka

    cout << "Combinations: " << combinations(encoded_str, 0, false, higher_bound) << endl;
}