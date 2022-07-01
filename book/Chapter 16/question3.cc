#include <bits/stdc++.h>
#include <thread>

using namespace std;

struct philosopher
{
    int position;

    void get(char *arr)
    {
        auto l = [](char *arr, int position) {
            arr[position - 1] = 'x';
        };
        auto r = [](char *arr, int position) {
            arr[position + 1] = 'x';
        };

        if (position == 5)
        {
            thread rt(r, arr, position);
            thread lt(l, arr, position);
            lt.join(), rt.join();
        }
        else
        {
            thread lt(l, arr, position);
            thread rt(r, arr, position);

            lt.join(), rt.join();
        }
    }
};

void test()
{
    char arr[9] = {'s', 'p', 's', 'p', 's', 'p', 's', 'p', 's'};
    philosopher ps[4] = {
        philosopher{.position = 1},
        philosopher{.position = 3},
        philosopher{.position = 5},
        philosopher{.position = 7},
    };

    thread ts[4];
    for (int i = 0; i < 4; i++)
    {
        ts[i] = thread(&philosopher::get, ps[i], arr);
    }
    for (int i = 0; i < 4; i++)
    {
        ts[i].join();
    }

    for (auto a : arr)
    {
        cout << a << " ";
    }
    cout << endl;
}

int main()
{
    while (true)
        test();
}