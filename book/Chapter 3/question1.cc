#include <bits/stdc++.h>
#include "Stack.h"
#include "Queue.h"

using namespace std;

class PartitionedStack
{
public:
    PartitionedStack()
    {
    }
    void Push(int data, int partition)
    {
        if (indices[partition] > -1 && indices[partition] >= (partition + 1) * STACK_SIZE)
        {
            printf("Stack is full");
            return;
        }

        if (indices[partition] == -1)
            indices[partition] = partition * STACK_SIZE;
        else
            indices[partition]++;

        stacks[indices[partition]] = data;
    }
    int Pop(int partition)
    {
        if (indices[partition] >= partition * STACK_SIZE)
        {
            return stacks[indices[partition]--];
        }
        else
        {
            return INT_MIN;
        }
    }
    bool IsEmpty(int partition)
    {
        return indices[partition] < partition * STACK_SIZE;
    }
    void Print()
    {
        for (int i = 0; i < NUM_STACKS; i++)
        {
            cout << "partition " << i << ": " << indices[i] << " - ";
            for (int j = i * STACK_SIZE; j <= indices[i]; j++)
            {
                cout << stacks[j] << " ";
            }
            cout << endl;
        }
    }

private:
    static const unsigned short int NUM_STACKS = 3, STACK_SIZE = 100;
    int stacks[NUM_STACKS * STACK_SIZE] = {INT_MIN};
    short int indices[NUM_STACKS] = {-1, -1, -1};
};

int main()
{
    PartitionedStack stack;
    stack.Push(10, 0);
    stack.Push(11, 1);
    stack.Push(50, 1);
    stack.Push(12, 2);
    stack.Push(13, 2);
    stack.Push(14, 2);

    stack.Print();

    while (!stack.IsEmpty(2))
    {
        cout << stack.Pop(2) << endl;
    }
    while (!stack.IsEmpty(0))
    {
        cout << stack.Pop(0) << endl;
    }

    stack.Print();
}