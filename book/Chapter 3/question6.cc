#include <bits/stdc++.h>

class MaxStack
{
public:
    MaxStack()
    {
        stack = 0;
        next_stack = 1;
    }
    void Push(int data)
    {
        stacks[stack].push(data);
    }
    int Peek()
    {
        return PeekAndPop(false);
    }
    void Pop()
    {
        PeekAndPop(true);
    }
    bool IsEmpty()
    {
        return stacks[stack].empty();
    }

private:
    std::stack<int> stacks[2];
    unsigned short int stack : 1, next_stack : 1;
    bool max_on_top = false;

    int PeekAndPop(bool pop = false)
    {
        int max = INT_MIN;
        if (max_on_top && pop)
        {
            max = stacks[stack].top();
            stacks[stack].pop();
            max_on_top = false;

            return max;
        }

        while (!stacks[stack].empty())
        {
            int data = stacks[stack].top();
            stacks[stack].pop();
            if (data > max)
            {
                if (max != INT_MIN)
                    stacks[next_stack].push(max);

                max = data;
            }
            else
            {
                stacks[next_stack].push(data);
            }
        }
        stack++, next_stack++;

        if (!pop)
        {
            stacks[stack].push(max);
            max_on_top = true;
        }

        return max;
    }
};

class MaxStack2
{
public:
    MaxStack2()
    {
        stack = 0;
        next_stack = 1;
    }
    void Push(int data)
    {
        if ((stacks[stack].empty() && stacks[next_stack].empty()) || stacks[stack].top() < data)
        {
            stacks[stack].push(data);
        }
        else
        {
            if (!stacks[next_stack].empty() && stacks[next_stack].top() > data)
            {
                int top = stacks[next_stack].top();
                stacks[next_stack].pop();
                stacks[next_stack].push(data);
                stacks[next_stack].push(top);
            }
            else
            {
                stacks[next_stack].push(data);
            }
        }
    }
    int Peek()
    {
        return PeekAndPop(false);
    }
    void Pop()
    {
        PeekAndPop(true);
    }
    bool IsEmpty()
    {
        return stacks[stack].empty() && stacks[next_stack].empty();
    }

private:
    std::stack<int> stacks[2];
    unsigned short int stack : 1, next_stack : 1;
    bool max_on_top = false;

    int PeekAndPop(bool pop = false)
    {
        int ret = INT_MIN;
        if (stacks[stack].empty() && stacks[next_stack].empty())
        {
            return ret;
        }

        if (stacks[next_stack].empty() || (!stacks[stack].empty() && stacks[stack].top() >= stacks[next_stack].top()))
        {
            ret = stacks[stack].top();
            if (pop)
                stacks[stack].pop();
        }
        else if (stacks[stack].empty() || (!stacks[next_stack].empty() && stacks[stack].top() <= stacks[next_stack].top()))
        {
            ret = stacks[next_stack].top();
            if (pop)
                stacks[next_stack].pop();
        }

        return ret;
    }
};

int main()
{
    MaxStack2 stack;
    stack.Push(5);
    stack.Push(50);
    stack.Push(500);
    stack.Push(4);
    stack.Push(40);
    stack.Push(10);
    stack.Push(1);

    while(!stack.IsEmpty())
    {
        int data = stack.Peek();
        stack.Pop();

        std::cout << data << std::endl;
    }
}