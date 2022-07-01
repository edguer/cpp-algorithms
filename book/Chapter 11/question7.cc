#include <bits/stdc++.h>
#include "qsort.hh"
#include "util.hh"
#include <cmath>

using namespace std;

struct person
{
    unsigned short int height : 2;
    unsigned short int weight : 8;
    bool operator<(const person &p)
    {
        return height <= p.height && weight <= p.weight;
    }
    operator std::string()
    {
        return "(h:" + to_string(height) + ", w:" + to_string(weight) + ")";
    }
};

class pheap
{
public:
    void add(person p)
    {
        heap[count++] = p;
        bubble(count - 1);
    }
    void fprint()
    {
        contoso::print(heap, count);
    }
    void sprint()
    {
        queue<int> q;
        q.push(0);
        int original_level_count = 1, level_count = 1, level = 0;
        cout << ++level << ": ";

        while (!q.empty())
        {
            int index = q.front();
            q.pop();

            if (index < count)
            {
                string item = heap[index];
                cout << item << " ";
                if (--level_count == 0)
                {
                    cout << endl;
                    original_level_count = level_count = pow(2, original_level_count);
                    cout << ++level << ": ";
                }

                q.push(left(index));
                q.push(right(index));
            }
        }

        cout << endl;
    }

private:
    static const unsigned int SIZE = 50;
    person heap[SIZE];
    unsigned int count = 0;

    void bubble(unsigned int index)
    {
        unsigned int parent_index = parent(index);
        if (heap[index] < heap[parent_index])
        {
            person temp = heap[index];
            heap[index] = heap[parent_index];
            heap[parent_index] = temp;

            if (parent_index > 0)
                bubble(parent_index);
        }
    }

    int parent(unsigned int index)
    {
        return index <= 2 ? 0 : (index - 1) / 2;
    }

    int left(unsigned int index)
    {
        return (2 * index) + 1;
    }
    int right(unsigned int index)
    {
        return (2 * index) + 2;
    }
};

int main()
{
    pheap h;
    h.add(person{.height = 1, .weight = 76});
    h.add(person{.height = 1, .weight = 70});
    h.add(person{.height = 2, .weight = 70});
    h.add(person{.height = 1, .weight = 69});
    h.fprint();
    h.sprint();
}