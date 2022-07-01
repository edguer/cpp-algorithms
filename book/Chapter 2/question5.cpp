#include <bits/stdc++.h>
#include "Node.cpp"

using namespace std;

// O(d)
Node *BuildDigit(unsigned short int data)
{
    unsigned short int divisor_factor = 1;
    Node *head = NULL;
    Node *current = NULL;
    unsigned short int digit = (data % (10 * divisor_factor)) / divisor_factor;
    while (data / divisor_factor)
    {
        if (!head)
        {
            current = head = new Node(digit);
        }
        else
        {
            current->SetNext(new Node(digit));
            current = current->GetNext();
        }
        divisor_factor *= 10;
        digit = (data % (10 * divisor_factor)) / divisor_factor;
    }

    return head;
}

int BuildNumber(Node *head)
{
    unsigned short int multiplier_factor = 1;
    int ret = 0;
    Node *current = head;
    while (current)
    {
        ret += current->GetData() * multiplier_factor;
        current = current->GetNext();
        multiplier_factor *= 10;
    }

    return ret;
}

// O(n + m + k)
Node *Divide(Node *number, Node *divisor)
{
    int n = BuildNumber(number);
    int d = BuildNumber(divisor);

    int result = n / d;

    return BuildDigit(result);
}

Node *Addition(Node *n1, Node *n2)
{
    Node *cur1 = n1, *cur2 = n2, *new_node = NULL;
    Node *cur = new_node;
    unsigned short int rest = 0;
    while (cur1 || cur2 || rest > 0)
    {
        int sum = rest;
        rest = 0;

        if (cur1)
            sum += cur1->GetData(), cur1 = cur1->GetNext();
        
        if (cur2)
            sum += cur2->GetData(), cur2 = cur2->GetNext();

        if (sum >= 10)
            rest = 1, sum -= 10;

        if (!new_node)
            cur = new_node = new Node(sum);
        else
            cur->SetNext(new Node(sum)), cur = cur->GetNext();
    }

    return new_node;
}

int main()
{
    cout << (699 % 1000) / 100 << endl;
    return 0;
    Node *number = BuildDigit(333);
    number->Print();

    Node *divisor = BuildDigit(999);
    divisor->Print();

    Divide(number, divisor)->Print();
    Addition(number, divisor)->Print();
}