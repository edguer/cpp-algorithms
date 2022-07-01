#include <bits/stdc++.h>

using namespace std;

unsigned int search(string term, string *arr, unsigned int start, unsigned int end)
{
    if (end >= start)
    {
        unsigned int mid = (start + end) / 2;
        if (arr[mid] == term)
        {
            return mid;
        }
        else if (arr[mid] == "")
        {
            int res_right = search(term, arr, mid + 1, end);
            if (res_right != -1)
                return res_right;

            int res_left = search(term, arr, start, mid - 1);
            return res_left;
        }
        else if (term < arr[mid])
        {
            return search(term, arr, start, mid - 1);
        }
        else
        {
            return search(term, arr, mid + 1, end);
        }
    }
    else
    {
        return -1;
    }
}

int main()
{
    string str[] = {"at", "", "bacon", "", "", "", "", "street", "", "swell"};
    unsigned int len = sizeof(str) / sizeof(string);
    cout << "Result: " << search("swell", str, 0, len - 1) << endl;
}