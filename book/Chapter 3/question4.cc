#include <bits/stdc++.h>
#include "Stack.h"

using namespace std;

// Hanoi tower challenge
int main()
{
    unsigned short int size = 20;

    Stack stack1(false);
    Stack stack2(false);
    Stack stack3(false);

    for (unsigned short int i = size; i > 0; i--)
    {
        stack1.Push(i);
    }

    cout << "Stack 1 (original): ";
    stack1.Print();

    while (!stack1.IsEmpty())
    {
        stack2.Push(stack1.Pop());
    }
    
    while (!stack2.IsEmpty())
    {
        stack3.Push(stack2.Pop());
    }

    cout << "Stack 1: ";
    stack1.Print();
    
    cout << "Stack 2: ";
    stack2.Print();

    cout << "Stack 3: ";
    stack3.Print();
}