#include <bits/stdc++.h>

using namespace std;

void print(char *str, int len)
{
    cout << "Permutation: ";
    for (int i = 0; i < len; i++)
    {
        cout << str[i];
    }
    cout << endl;
}

void swap(char *arr, int index1, int index2)
{
    char temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

char *copy(char *arr, int len)
{
    char *ret = new char[len];
    for (int i = 0; i < len; i++)
    {
        ret[i] = arr[i];
    }
    return ret;
}

void permutate(char *arr, int index1, int index2, int n)
{
    char c = arr[index1];
    int next_place = index2;
    for (int j = index1; j < n - 1; j++)
    {
        if (j < next_place)
            arr[j] = arr[j + 1];
        else if (j == next_place)
            arr[j] = c;
    }
    print(arr, n);
}

void permutations(int n)
{
    if (n % 2 != 0)
    {
        cout << "N should be even" << endl;
    }

    char right = ')';
    char left = '(';
    char original[n];
    for (int i = 0; i < n / 2; i++)
    {
        original[i] = left;
        original[(n / 2) + i] = right;
    }

    print(original, n);

    for (int j = 0; j < n/2; j++)
    {
        for (int i = 0; i < n - 2; i++)
        {
            // permutate(original, i, (n / 2) + i, n);
            swap(original, i, i + 1);
            print(original, n);
            // permutate(copy(original, n), (n / 2) + i, i + 1, n);
            // break;
        }
    }
}

int main()
{
    /**
    * n must be even, for each 2, I have a ( and a )
    * n = 2: ()
    * n = 4: ()(), (())
    * n = 6: ()()(), ()(()), ((())), (()())
    * n = 8: ()()()(), ()()(()), ()((())), (((()))), 
    * Start by stacking all ( followed by ) -> (((())))
    * From middle to left, move first ) until 0
    * From middle to right, move first ( until the end
    * */
    permutations(8);
}