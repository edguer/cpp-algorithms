#include <bits/stdc++.h>
#include "Stack.h"

using namespace std;

class MyQueue
{
public:
    MyQueue() : entry(false), exit(false)
    {
    }
    void Push(int data)
    {
        if (entry.IsEmpty())
        {
            while (!exit.IsEmpty())
            {
                entry.Push(exit.Pop());
            }
        }
        entry.Push(data);
    }
    int Pop()
    {
        int ret = INT_MAX;
        while (!entry.IsEmpty())
        {
            exit.Push(entry.Pop());
        }

        if (!exit.IsEmpty())
            ret = exit.Pop();

        return ret;
    }

private:
    Stack entry, exit;
};

int main()
{
    MyQueue queue;
    queue.Push(5);
    queue.Push(50);
    queue.Push(500);
    queue.Push(500);
    queue.Pop();
    queue.Push(24);
    queue.Push(550);
    queue.Push(0);

    int value = INT_MAX;
    do
    {
        value = queue.Pop();
        cout << "Pop: " << value << endl;
    } while (value != INT_MAX);
}