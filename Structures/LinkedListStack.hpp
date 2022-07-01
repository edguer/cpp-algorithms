#include <bits/stdc++.h>

#ifndef LINKEDLISTSTACK
#define LINKEDLISTSTACK

using namespace std;

class StackNode
{
public:
    StackNode(int value)
    {
        next = NULL;
        previous = NULL;
        this->value = value;
    }
    int GetValue()
    {
        return value;
    }
    void SetValue(int value)
    {
        this->value = value;
    }
    StackNode* GetNext()
    {
        return next;
    }
    void SetNext(StackNode* node)
    {
        next = node;
    }
    StackNode* GetPrevious()
    {
        return previous;
    }
    void SetPrevious(StackNode* node)
    {
        previous = node;
    }
private:
    StackNode* next;
    StackNode* previous;
    int value;
};

class LinkedListStack
{
public:
    LinkedListStack()
    {
        front = NULL;
        rear = NULL;
    }
    void Push(int value)
    {
        if (front == NULL)
        {
            front = rear = new StackNode(value);
            front->SetNext(rear);
            rear->SetPrevious(front);
        }
        else
        {
            StackNode* new_node = new StackNode(value);
            new_node->SetPrevious(rear);
            rear->SetNext(new_node);
            rear = new_node;
        }
    }
    int Pull()
    {
        if (rear == NULL)
        {
            printf("Stack is empty");
            return -100;
        }
        else
        {
            int ret = rear->GetValue();
            rear = rear->GetPrevious();

            return ret;
        }
    }
private:
    StackNode* front;
    StackNode* rear;
};

#endif