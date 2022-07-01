#include <bits/stdc++.h>

#ifndef QUEUE
#define QUEUE

using namespace std;

struct Queue
{
    int front, rear, capacity;
    int *queue;

    Queue(int c)
    {
        front = rear = 0;
        capacity = c;
        queue = new int;
    }

    ~Queue()
    {
        delete[] queue;
    }

    void Enqueue(int data)
    {
        if (rear == capacity)
        {
            printf("Queue is full");
        }
        else
        {
            queue[rear++] = data;
        }
    }

    int Dequeue()
    {
        if (front == rear)
        {
            printf("Queue is empty");
            return 0;
        }
        else
        {
            int ret = queue[front];
            for (int i = 0; i < rear - 1; i++)
            {
                queue[i] = queue[i + 1];
            }
            rear--;
            return ret;
        }
    }

    void PrintQueue()
    {
        for (int i = 0; i < rear; i++)
        {
            cout << "position " << i << ", item " << queue[i] << endl;
        }
    }

    bool IsEmpty()
    {
        return rear == 0;
    }
};

#endif