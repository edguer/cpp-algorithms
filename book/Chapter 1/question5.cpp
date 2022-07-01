#include <bits/stdc++.h>
#include "utils.hpp"
#include <charconv>
using namespace std;

string str = "abcdhhhhhherjjjj";
string new_str;

//O(n), space O(2n)
void CompressNewString()
{
    char *last_char = NULL;
    unsigned short int last_char_count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (last_char == NULL || *last_char != str.at(i))
        {
            if (last_char_count > 0)
            {
                new_str += std::to_string(last_char_count + 1);
            }

            new_str += str.at(i);
            last_char = &str.at(i);
            last_char_count = 0;
        }
        else if (*last_char == str.at(i))
        {
            last_char_count++;
        }
    }

    if (last_char_count > 0)
    {
        new_str += std::to_string(last_char_count + 1);
    }
}

// O(n*k), space O(n)
void CompressSameString()
{
    char *last_char = NULL;
    char *c_str = new char[str.length()];
    strcpy(c_str, str.c_str());
    unsigned short int last_char_count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (last_char == NULL || *last_char != c_str[i])
        {
            if (last_char_count > 0)
            {
                std::to_chars(&c_str[i - last_char_count], &c_str[i], last_char_count + 1);
                int current_index = i;
                for (int j = i - last_char_count + 1; j < str.length(); j++)
                {
                    c_str[j] = c_str[current_index++];
                }
            }

            last_char = &c_str[i];
            last_char_count = 0;
        }
        else if (*last_char == c_str[i])
        {
            last_char_count++;
        }
    }
}

int main()
{
    Run(CompressNewString);
    // cout << new_str << endl;
}