#include <bits/stdc++.h>
#include <chrono> 

using namespace std;

void Reverse(char *str)
{
    int len = sizeof(str);
    int left = 0;
    int right = len - 1;

    while (right - left > 0)
    {
        cout << "replacing " << str[left] << " with " << str[right] << " left " << left << " right " << right << endl;
        int temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++, right--;
    }
}

// much more effective in terms of coding - simpler because only uses pointer operations.
void ReverseSavvy(char *str)
{
    // end pointing to str
    char *end = str;
    // check str is null
    if (*str)
    {
        // while end is not null, I will increse its current memory address.
        while (*end)
        {
            *end++;
        }
        // decrease by one, since the last address is necessarily null
        *end--;

        // while current str address is less then current end address, do the following
        while (str < end)
        {
            // put current str address into a char variable
            char temp = *str;
            // current str address will receive current end address, meanwhile we increase str adress and decrease end address.
            *str++ = *end;
            *end-- = temp;
        }
    }
}

int main()
{
    string str = "my test   ";

    char c_str[20] = { NULL };
    strcpy(c_str, str.c_str());

    auto start = chrono::high_resolution_clock::now(); 
    ReverseSavvy(c_str);
    auto stop = chrono::high_resolution_clock::now();
    cout << "Execution time: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << endl;
    
    for (int i = 0; i < 20; i++)
    {
        cout << c_str[i];
    }
    cout << endl;
}
