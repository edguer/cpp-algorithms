#include <bits/stdc++.h>

using namespace std;

class StackNode
{
public:
    explicit StackNode(int data)
    {
        this->data = data;
        previous = NULL;
    }
    StackNode *GetPrevious()
    {
        return previous;
    }
    void SetPrevious(StackNode *node)
    {
        previous = node;
    }
    int GetData()
    {
        return data;
    }

private:
    int data;
    StackNode *previous;
};

class Stack
{
public:
    explicit Stack(bool track_min)
    {
        tail = NULL;
        if (track_min)
            min_stack = new Stack(false);
    }
    explicit Stack(bool track_min, unsigned long capacity)
    {
        tail = NULL;
        this->capacity = capacity;
        if (track_min)
            min_stack = new Stack(false);
    }
    Stack(const Stack &p)
    {
        tail = p.tail;
        min = p.min;
        capacity = p.capacity;
        count = p.count;
        min_stack = p.min_stack;
    }
    void Push(int data)
    {
        if (IsFull())
        {
            printf("Stack is full");
            return;
        }

        StackNode *new_node = new StackNode(data);
        if (!tail)
        {
            tail = new_node;
        }
        else
        {
            new_node->SetPrevious(tail);
            tail = new_node;
            if (min_stack && data < min)
                min_stack->Push(min);
        }

        if (data < min)
            min = data;

        count++;
    }
    int Pop()
    {
        int ret = INT_MIN;
        if (tail)
        {
            ret = tail->GetData();
            tail = tail->GetPrevious();

            if (min_stack && ret == min)
            {
                min_stack->Print();
                min = min_stack->Pop();
            }
        }

        count--;

        return ret;
    }
    int Peek()
    {
        int ret = INT_MIN;
        if (tail)
        {
            ret = tail->GetData();
        }

        return ret;
    }
    int GetMin()
    {
        return min;
    }
    bool IsEmpty()
    {
        return !tail;
    }
    void Print()
    {
        StackNode *node = tail;
        while (node)
        {
            cout << node->GetData() << " ";
            node = node->GetPrevious();
        }

        cout << endl;
    }
    bool IsFull()
    {
        return count == capacity;
    }

private:
    StackNode *tail;
    int min = INT_MAX;
    unsigned long capacity = LONG_MAX, count = 0;
    Stack *min_stack = NULL;
};