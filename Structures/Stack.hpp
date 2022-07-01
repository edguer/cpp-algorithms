#include <bits/stdc++.h>

#ifndef STACK
#define STACK

using namespace std;

class Stack
{
public:
    Stack(int capacity)
    {
        this->capacity = capacity;
        this->stack = new int[size];
        this->size = 0;
    }
    void Push(int value)
    {
        stack[size++] = value;
    }
    int Pull()
    {
        return stack[--size];
    }
private:
    int* stack;
    int size, capacity;
};

#endif