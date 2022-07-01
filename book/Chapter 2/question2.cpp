#include <bits/stdc++.h>
#include "Node.cpp"

using namespace std;

// O(n + k)
void Naive()
{
    Node *head = Node::GenerateNode();
    unsigned short int k = 1;

    Node *cur_node = head;
    Node *last = NULL;
    unsigned short int count = 0;
    while (cur_node)
    {
        last = cur_node;
        cur_node = cur_node->GetNext();
        count++;
    }

    for (int i = count; i > count - k; i--)
    {
        last = last->GetPrevious();
    }

    head->Print();  
    cout << last->GetData() << endl;
}

// O(n), using 2 needles in a single pass.
void Savvy(unsigned short int k)
{
    Node *head = Node::GenerateNode();

    Node *cur_node = head;
    Node *lag = cur_node;
    unsigned short int count = 0;
    while (cur_node)
    {
        if (count > k)
        {
            lag = lag->GetNext();
        }

        cur_node = cur_node->GetNext();
        count++;
    }

    if (count - 1 < k)
    {
        cout << "k too long" << endl;
        return;
    }

    head->Print();
    cout << lag->GetData() << endl;
}

int Recursive(Node *node, unsigned short int k)
{
    if (node == NULL)
    {
        return 0;
    }
    
    int i = Recursive(node->GetNext(), k) + 1;
    if (i - 1 == k)
    {
        cout << "found " << node->GetData() << endl;
    }

    return i;
}

int main()
{
    Node *head = Node::GenerateNode();
    head->Print();
    Recursive(head, 2);
}