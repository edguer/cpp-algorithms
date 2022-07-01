#include <bits/stdc++.h>

using namespace std;

class MaxHeap
{
public:
    // O(logN)
    void Add(int data)
    {
        if (count >= CAPACITY)
        {
            printf("Heap is full.");
            return;
        }

        heap[count++] = data;
        BubbleUp(count - 1);
    }
    // O(logN)
    int PopMax()
    {
        int ret = heap[0];
        heap[0] = heap[--count];
        SinkDown(0);

        return ret;
    }
    void Print()
    {
        for (unsigned short int i = 0; i < count; i++)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
private:
    unsigned short int count = 0;
    static const unsigned short int CAPACITY = 10;
    int heap[CAPACITY] = { INT_MIN };

    // O(logN)
    void BubbleUp(unsigned short int index)
    {
        while (index > 0 && heap[GetParent(index)] < heap[index])
        {
            unsigned short int parent_index = GetParent(index);
            Swap(index, parent_index);
            index = parent_index;
        }
    }

    // O(logN)
    void SinkDown(unsigned short int index)
    {
        unsigned short int left = GetLeft(index);
        unsigned short int right = GetRight(index);
        unsigned short int biggest = index;

        if (heap[left] > heap[biggest])
            biggest = left;

        if (heap[right] > heap[biggest])
            biggest = right;

        if (biggest != index)
        {
            Swap(index, biggest);
            SinkDown(biggest);
        }
    }

    void Swap(unsigned short int index1, unsigned short int index2)
    {
        int temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }

    unsigned short int GetParent(unsigned short int index)
    {
        return index <= 1 ? 0 : (index - 1) / 2;
    }
    unsigned short int GetLeft(unsigned short int index)
    {
        return (2 * index) + 1;
    }
    unsigned short int GetRight(unsigned short int index)
    {
        return (2 * index) + 2;
    }
};

int main()
{
    MaxHeap heap;
    heap.Add(1);
    heap.Add(5);
    heap.Add(10);
    heap.Add(15);
    heap.Add(20);
    heap.Add(25);

    heap.Print();

    heap.Add(50);
    cout << "Pop: " << heap.PopMax() << endl;
    cout << "Pop: " << heap.PopMax() << endl;
    heap.Print();
}