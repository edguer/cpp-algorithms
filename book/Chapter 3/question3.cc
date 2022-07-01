#include <bits/stdc++.h>
#include "Stack.h"

using namespace std;

class SetOfStacks
{
public:
    explicit SetOfStacks(unsigned long stacks_capacity = 5)
    {
        this->stacks_capacity = stacks_capacity;
        stacks.push_back(new Stack(false, stacks_capacity));
    }
    void Push(int data)
    {
        if (stacks[last_stack]->IsFull())
        {
            bool create_new = true;
            if (last_stack < stacks.size() - 1)
            {
                for (unsigned short int i = last_stack + 1; i < stacks.size(); i++)
                {
                    if (!stacks[i]->IsFull())
                    {
                        last_stack = i;
                        create_new = false;
                        break;
                    }
                }
            }

            if (create_new)
            {
                stacks.push_back(new Stack(false, stacks_capacity));
                last_stack++;
            }
        }

        stacks[last_stack]->Push(data);
    }
    int Pop()
    {
        int ret = stacks[last_stack]->Pop();
        if (stacks[last_stack]->IsEmpty())
        {
            stacks.erase(stacks.begin() + last_stack);
            last_stack--;
        }

        return ret;
    }
    int PopAt(unsigned short int stack)
    {
        int ret = INT_MAX;
        if (stack < stacks.size())
        {
            ret = stacks[stack]->Pop();
            if (stacks[stack]->IsEmpty())
            {
                stacks.erase(stacks.begin() + stack);
                last_stack = stacks.size() - 1;
            }
            else if (stack < last_stack)
            {
                last_stack = stack;
            }
        }

        return ret;
    }
    void Print()
    {
        for (unsigned short int i = 0; i < stacks.size(); i++)
        {
            cout << "stack " << i << " - ";
            cout << " full ? " << stacks[i]->IsFull() << ": ";

            stacks[i]->Print();
        }
        
    }
private:
    vector<Stack*> stacks;
    unsigned long stacks_capacity;
    unsigned short int last_stack = 0;
};

int main()
{
    SetOfStacks stacks(3);
    stacks.Push(1);
    stacks.Push(1);
    stacks.Push(1);
    stacks.Push(10);
    stacks.Push(10);
    stacks.Push(10);

    cout << "Pop: " << stacks.Pop() << endl;
    cout << "Pop: " << stacks.Pop() << endl;
    cout << "Pop: " << stacks.Pop() << endl;

    stacks.Push(20);
    stacks.Push(20);
    stacks.Push(20);

    stacks.Push(30);
    stacks.Push(30);
    stacks.Push(30);

    stacks.Push(40);
    stacks.Push(40);

    cout << "Pop at: " << stacks.PopAt(1) << endl;
    cout << "Pop at: " << stacks.PopAt(2) << endl;

    stacks.Push(40);
    stacks.Push(40);
    stacks.Push(40);

    stacks.Push(50),stacks.Push(50),stacks.Push(50);

    stacks.Print();
}