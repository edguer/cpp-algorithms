#include <bits/stdc++.h>
#include "Stack.h"

using namespace std;

int main()
{
    Stack stack(true);
    stack.Push(5);
    stack.Push(6);
    stack.Push(7);
    stack.Push(3);
    stack.Push(1);
    stack.Push(8);

    stack.Pop();
    cout << "Min: " << stack.GetMin() << endl;
}