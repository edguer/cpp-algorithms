#include <bits/stdc++.h>
#include "util.hh"

using namespace std;

class tracker
{
public:
    void track(int value)
    {
        if (count == 0)
            list[count++] = value;
        else
            track(value, 0, count - 1);
    }
    void print()
    {
        contoso::print(list, count);
    }
    int rank(int value)
    {
        int index = search(value, 0, count - 1);
        if (index > -1)
        {
            int next = index + 1;
            while (next < count && list[next] == value)
            {
                next++;
            }
            index = next - 1;
        }

        return index;
    }
private:
    static const int SIZE = 50;
    int count = 0;
    int list[SIZE + 1];

    void track(int value, int start, int end)
    {
        if (end >= start)
        {
            int mid = (start + end) / 2;
            if (list[mid] == value || (value >= list[mid] && mid == count - 1) || (value >= list[mid] && mid < count && value <= list[mid + 1]))
                insert(value, mid + 1);
            else if ((value < list[mid] && mid == 0) || (value < list[mid] && mid > 0 && value >= list[mid - 1]))
                insert(value, mid);
            else if (value < list[mid])
                track(value, start, mid - 1);
            else
                track(value, mid + 1, end);
        }
    }
    void insert(int value, int index)
    {
        for (int i = SIZE; i > index; i--)
        {
            list[i] = list[i - 1];
        }
        list[index] = value;
        count++;
    }

    int search(int value, int start, int end)
    {
        if (end > start)
        {
            int mid = (start + end) / 2;
            if (list[mid] == value)
                return mid;
            else if (value > list[mid])
                return search(value, mid, end);
            else
                return search(value, start, mid);
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    tracker t;
    t.track(5);
    t.track(1);
    t.track(7);
    t.track(0);
    t.track(5);
    t.track(10);
    t.print();

    cout << "rank: " << t.rank(1) << endl;
}