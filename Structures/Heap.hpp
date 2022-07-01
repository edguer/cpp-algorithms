#include <bits/stdc++.h>

#ifndef HEAP
#define HEAP

using namespace std;

class MaxHeap
{
public:
    MaxHeap()
    {
    }
    MaxHeap(int *feed, int len)
    {
        for (int i = 0; i < len; i++)
        {
            Insert(feed[i]);
        }
    }
    // O(logN)
    void Insert(int value)
    {
        int index = current_index++;
        array[index] = value;

        BubbleUp(index);
    }

    int ExtractMax()
    {
        if (current_index == 0)
        {
            return -1;
        }
        
        int ret = array[0];
        array[0] = array[--current_index];

        SinkDown(0);

        return ret;
    }

    void Print()
    {
        cout << "Heap array: ";
        for (int i = 0; i < current_index; i++)
        {
            cout << array[i] << "(" << i << ") ";
        }
        cout << endl;
    }

    void Heapify()
    {
        for (int j = 0; j < current_index / 2; j++)
        {
            for (int i = 0; i < current_index; i++)
            {
                SinkDown(i);
            }
        }
    }

private:
    int array[100];
    int current_index = 0;

    int GetParentIndex(int index)
    {
        return index <= 1 ? 0 : (index - 1) / 2;
    }

    int GetLeftIndex(int parent_index)
    {
        return (2 * parent_index) + 1;
    }

    int GetRightIndex(int parent_index)
    {
        return (2 * parent_index) + 2;
    }

    void Swap(int index1, int index2)
    {
        int temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }

    void BubbleUp(int index)
    {
        while (index > 0 && array[GetParentIndex(index)] < array[index])
        {
            Swap(index, GetParentIndex(index));
            index = GetParentIndex(index);
        }
    }

    void SinkDown(int index)
    {
        int left = GetLeftIndex(index);
        int biggest = index;
        if (left < current_index && array[left] > array[biggest])
        {
            biggest = left;
        }

        int right = GetRightIndex(index);
        if (right < current_index && array[right] > array[biggest])
        {
            biggest = right;
        }

        if (biggest != index)
        {
            Swap(index, biggest);
            SinkDown(biggest);
        }
    }
};

#endif