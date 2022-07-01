#include <bits/stdc++.h>

using namespace std;

void get_permutations(const char *str, char *permutation, long *visited, int level, int end)
{
    for (int i = 0; i <= end; i++)
    {
        if (((*visited) & (1 << i)) > 0)
            continue;

        if (!permutation)
            permutation = new char[end + 1];

        permutation[level] = str[i];
        (*visited) |= 1 << i;
        if (level == end)
        {
            cout << "Permutation: ";
            for (int j = 0; j <= end; j++)
            {
                cout << permutation[j];
            }
            cout << endl;
        }
        else
        {
            get_permutations(str, permutation, visited, level + 1, end);
        }
        (*visited) ^= 1 << i;
    }
}

int count_permutations(int len)
{
    if (len == 0)
        return 0;

    int res = 1;
    for (int i = 1; i <= len; i++)
    {
        res *= i;
    }
    return res;
}

int main()
{
    string str = "abcd";
    long visited = 0;
    get_permutations(str.c_str(), NULL, &visited, 0, str.length() - 1);
    cout << "Permutations: " << count_permutations(str.length()) << endl;
    /**
     * abc
     * acb
     * bac
     * bca
     * cab
     * cba
     * */
}