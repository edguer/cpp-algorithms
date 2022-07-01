#include <bits/stdc++.h>
#include "util.hh"

using namespace std;

//O(n+k), k=256. Memory: 2k
bool is_anagram(string &str1, string &str2)
{
    if (str1.length() != str2.length())
        return false;

    unsigned short int str1_count[256] = { 0 }, str2_count[256] = { 0 };
    for (unsigned short int i1 = 0, i2 = 0; i1 < str1.length() || i2 < str2.length(); i1++, i2++)
    {
        if (i1 < str1.length())
            str1_count[str1.at(i1)]++;
        if (i2 < str2.length())
            str2_count[str2.at(i2)]++;
    }
    
    for (unsigned short int i = 0; i < 256; i++)
    {
        if (str1_count[i] != str2_count[i])
            return false;
    }
    
    return true;
}

// O(n2/2)
void sort(string *arr, unsigned short int len)
{
    for (unsigned short int i = 0; i < len; i++)
    {
        unsigned short int next = i + 1;
        for (unsigned short int j = next; j < len; j++)
        {
            if (is_anagram(arr[i], arr[j]))
            {
                string temp = arr[next];
                arr[next] = arr[j];
                arr[j] = temp;
                next++;
            }
        }
    }
    
}

int main()
{
    string strs[] = { "abc", "olol", "edu", "ude", "bca", "gue", "lolo" };
    unsigned short int len = sizeof(strs)/sizeof(string);
    sort(strs, len);
    contoso::print(strs, len);
}