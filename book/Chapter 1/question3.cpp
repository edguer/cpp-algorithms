#include <bits/stdc++.h>

using namespace std;

void QuickSort(char *str, int start, int end)
{
    if (end > start)
    {
        char pivot = *(str + end);
        int i = start - 1;
        for (int j = start; j < end; j++)
        {
            if (str[j] < pivot)
            {
                char temp = str[++i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
        char temp = str[++i];
        str[i] = str[end];
        str[end] = temp;

        QuickSort(str, start, i - 1);
        QuickSort(str, i + 1, end);
    }
}

bool IsEqual(char *str1, int str1_size, char *str2, int str2_size)
{
    if (str1_size != str2_size)
    {
        return false;
    }

    while (*str1 && *str2)
    {
        if (*str1++ != *str2++)
        {
            return false;
        }
    }

    return true;
}

bool IsPermutationNaive(string *str1, string *str2)
{
    if (str1->length() != str2->length())
    {
        return false;
    }

    char c_str1[str1->length()];
    strcpy(c_str1, str1->c_str());

    char c_str2[str2->length()];
    strcpy(c_str2, str2->c_str());

    QuickSort(c_str1, 0, str1->length() - 1);
    QuickSort(c_str2, 0, str2->length() - 1);

    return IsEqual(c_str1, str1->length(), c_str2, str2->length());
}

bool IsPermutationSavvy(const char *str1, int str1_size, const char *str2, int str2_size)
{
    if (str1_size != str2_size)
    {
        return false;
    }

    unsigned short int char_count[256] = { 0 };
    while (*str1 && *str2)
    {
        ++char_count[*str1++], ++char_count[*str2++];
    }

    for (int i = 0; i < 256; i++)
    {
        if (char_count[i] % 2 > 0)
        {
            return false;
        }
    }
    
    return true;
}

bool IsPermutationSavvyImproved(const char *str1, int str1_size, const char *str2, int str2_size)
{
    if (str1_size != str2_size)
    {
        return false;
    }

    unsigned short int char_count[1000] = { 0 };
    unsigned short int visited_chars[str1_size + str2_size];
    unsigned short int visited_chars_count = 0;
    while (*str1 && *str2)
    {
        visited_chars[visited_chars_count++] = *str1;
        visited_chars[visited_chars_count++] = *str2;

        ++char_count[*str1++], ++char_count[*str2++];
    }

    // passes 2 times in the same character, but who cares? Better than visiting the 1000 unicode characters.
    for (int i = 0; i < visited_chars_count; i++)
    {
        if (char_count[visited_chars[i]] % 2 > 0)
        {
            return false;
        }
    }
    
    return true;
}

// know if a string a permutation of another
// 2 methods:
//  1. count all characters in both strings and compare. Time is O(2n + k), space is O(2n + k), where k is the number of possible characters (256 for ASCII).
//  2. order both strings and directly compare. Using quick sort, time is O(2 * NlogN + n) and space is O(2n)
int main()
{
    string str1 = "eduar%$do";
    string str2 = "eduar%$do";

    const char *s  = u8"\u0444";
    cout << (int)*s << endl;

    auto start = chrono::high_resolution_clock::now(); 
    // bool res = IsPermutationNaive(&str1, &str2);
    bool res = IsPermutationSavvy(str1.c_str(), str1.length(), str2.c_str(), str2.length());
    // bool res = IsPermutationSavvyImproved(str1.c_str(), str1.length(), str2.c_str(), str2.length());
    auto stop = chrono::high_resolution_clock::now();
    cout << "Execution time: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << endl;

    cout << res << endl;
}