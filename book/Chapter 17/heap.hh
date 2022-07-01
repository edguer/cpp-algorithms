#include <bits/stdc++.h>
#include <cmath>

#ifndef HEAP
#define HEAP

using namespace std;

namespace contoso
{
    class max_heap
    {
    public:
        max_heap(unsigned int capacity = 200)
        {
            this->capacity = capacity;
            count = 0;
            heap = new int[capacity];
        }

        void push(int value)
        {
            heap[count++] = value;
            bubble(count - 1);
        }

        int pop()
        {
            int res = heap[0];
            heap[0] = heap[--count];
            sink(0);
            return res;
        }

        void print()
        {
            unsigned int index = 0, level = 0;
            while (index < count)
            {
                cout << (level + 1) << ": ";
                unsigned int last_index = index + pow(2, level++);
                for (; index < count && index < last_index; index++)
                {
                    cout << heap[index] << " ";
                }
                cout << endl;
            }
        }

    private:
        int *heap;
        unsigned int capacity, count;

        void bubble(unsigned int index)
        {
            while (index > 0)
            {
                unsigned int parent_index = parent(index);
                if (heap[parent_index] < heap[index])
                    swap(&heap[parent_index], &heap[index]);
                
                index = parent_index;
            }
        }

        void sink(unsigned int index)
        {
            while (index < count)
            {
                unsigned int biggest_index = index;
                unsigned int left_index = left(index);
                unsigned int right_index = right(index);

                if (heap[left_index] > heap[biggest_index])
                    biggest_index = left_index;

                if (heap[right_index] > heap[biggest_index])
                    biggest_index = right_index;

                if (biggest_index != index)
                {
                    swap(&heap[biggest_index], &heap[index]);
                    index = biggest_index;
                }
                else
                {
                    break;
                }
            }
        }

        unsigned int parent(unsigned int index)
        {
            return index <= 1 ? 0 : (index - 1) / 2;
        }

        unsigned int left(unsigned int index)
        {
            return (index * 2) + 1;
        }

        unsigned int right(unsigned int index)
        {
            return (index * 2) + 2;
        }

        void swap(int *a, int *b)
        {
            *a = *a - *b; // a9 b5 - a4
            *b = *a + *b; // a4 b5 - b9
            *a = *b - *a; // a4 b9 - a5
        }
    };
}

#endif
