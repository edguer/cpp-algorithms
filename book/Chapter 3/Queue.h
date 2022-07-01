#include <bits/stdc++.h>

using namespace std;

class QueueNode
{
public:
    QueueNode(int data)
    {
        this->data = data;
        next = previous = NULL;
    }
    QueueNode *GetPrevious()
    {
        return previous;
    }
    void SetPrevious(QueueNode *node)
    {
        previous = node;
    }
    QueueNode *GetNext()
    {
        return next;
    }
    void SetNext(QueueNode *node)
    {
        next = node;
    }
    int GetData()
    {
        return data;
    } 
private:
    int data;
    QueueNode *next, *previous;
};

class Queue
{
public:
    Queue()
    {
        head = tail = NULL;
    }
    void Push(int data)
    {
        QueueNode *new_node = new QueueNode(data);
        if (head == NULL)
        {
            head = tail = new_node;
            head->SetNext(tail);
            tail->SetPrevious(head);
        }
        else
        {
            tail->SetNext(new_node);
            new_node->SetPrevious(tail);
            tail = new_node;
        }
    }
    int Pop()
    {
        int ret = INT_MIN;
        if (tail)
        {
            ret = head->GetData();
            QueueNode *node = head;
            head = head->GetNext();
            delete node;
        }

        return ret;
    }
    bool IsEmpty()
    {
        return !head;
    }
    void Print()
    {
        QueueNode *node = head;
        while(node)
        {
            cout << node->GetData() << " ";
            node = node->GetNext();
        }
        cout << endl;
    }
private:
    QueueNode *head, *tail;
};