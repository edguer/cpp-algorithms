#include <bits/stdc++.h>
#include "utils.hpp"

using namespace std;

string str = "Eduardo da Rocha Guerra Santos";
unsigned short int total_len = str.length() + (4 * 3);
char *c_str = new char[total_len];

// O(n + k*n/2)
void ReplaceSpace()
{
    strcpy(c_str, str.c_str());

    for (int i = 0; i < str.length(); i++)
    {
        if (c_str[i] == ' ')
        {
            for (int j = total_len - 1; j > i; j -= 2)
            {
                c_str[j + 2] = c_str[j];
                c_str[j + 1] = c_str[j - 1];
            }
            c_str[i] = '%', c_str[++i] = '2', c_str[++i] = '0';
        }
    }
}

// O(2n)
void ReplaceSpaceImproved()
{
    // first, gets the amount of space required
    strcpy(c_str, str.c_str());
    int space_count = 0, new_len = str.length();
    for (int i = 0; i < str.length(); i++)
        if (c_str[i] == ' ')
            space_count++;
    new_len += space_count * 2;

    // then, we start from the last character and goes until the first
    // then we place the last item from original string to the last place of the expanded string
    // we continue doing that by iterating both indices: the one of the original str and the one for expanded string
    // in case there is a space, we set the %20 in reverse and iterate the index for the expanded string 3 times.   
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (c_str[i] == ' ')
        {
            c_str[--new_len] = '0';
            c_str[--new_len] = '2';
            c_str[--new_len] = '%';
        }
        else
        {
            c_str[--new_len] = c_str[i];
        }
    }
    
}

int main()
{
    Run(ReplaceSpaceImproved);
    cout << c_str << endl;
}