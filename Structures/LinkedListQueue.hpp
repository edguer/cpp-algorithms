#include <bits/stdc++.h>

#ifndef LINKEDQUEUE
#define LINKEDQUEUE

using namespace std;

struct Node
{
    Node *next;
    Node *previous;
    int value;

    Node(int data)
    {
        value = data;
    }
};

struct LinkedQueue
{
    Node *front;
    Node *rear;

    LinkedQueue()
    {
        front = rear = NULL;
    }

    void Enqueue(int data)
    {
        Node *node = new Node(data);
        if (front == NULL && rear == NULL)
        {
            front = rear = node;
            front->next = rear;
            rear->previous = front;
        }
        else
        {
            node->previous = rear;
            rear->next = node;
            rear = node;
        }
    }

    int Dequeue()
    {
        if (front == NULL)
        {
            printf("Queue empty");
            return 0;
        }
        else
        {
            int ret = front->value;
            front = front->next;
            return ret;
        }
    }

    void Print(void)
    {
        if (front == NULL)
        {
            printf("Queue empty");
        }
        else
        {
            Node *cur_node = front;
            int count = 0;
            do
            {
                cout << "position " << count << ", value " << cur_node->value << endl;
                cur_node = cur_node->next;
                count++;
            } while (cur_node != NULL);
        }
    }
};

#endif