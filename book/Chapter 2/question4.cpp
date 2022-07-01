#include <bits/stdc++.h>
#include "Node.cpp"

using namespace std;

//O(n2), space complexity O(n)
Node *NaivePartition(Node *node, unsigned short int pivot)
{
    // 3, 50, 48, 1, 10, 2, 70, 80
    // we can do it in n2 by swaping values to the right
    int count = 0;
    for (int i = 0; i <= count; i++)
    {
        Node *cur2 = node;
        count = 0;
        while (cur2)
        {
            Node *next = cur2->GetNext();
            Node *previous = cur2->GetPrevious();
            if (cur2->GetData() > pivot && cur2->GetNext())
            {
                if (cur2 == node)
                {
                    node = cur2->GetNext();
                }

                cur2->SetNext(next->GetNext());
                cur2->SetPrevious(next);

                next->SetNext(cur2);
                next->SetPrevious(previous);

                if (previous)
                {
                    previous->SetNext(next);
                }
            }
            else
            {
                cur2 = cur2->GetNext();
            }
            count++;
        }
    }

    return node;
}

// O(n), space complexity O(2n)
Node *Savvy(Node *node, unsigned short int pivot)
{
    Node *start = NULL;
    Node *start_last = NULL;
    Node *end = NULL;
    Node *end_last = NULL;

    Node *cur = node;
    while (cur)
    {
        Node *new_node = new Node(cur->GetData());
        if (cur->GetData() <= pivot)
        {
            if (start == NULL)
            {
                start_last = start = new Node(cur->GetData());
            }
            else
            {
                start_last->SetNext(new_node);
                new_node->SetPrevious(start_last);

                start_last = new_node;
            }
        }
        else
        {
            if (end == NULL)
            {
                end_last = end = new Node(cur->GetData());
            }
            else
            {
                end_last->SetNext(new_node);
                new_node->SetPrevious(end_last);

                end_last = new_node;
            }
        }

        cur = cur->GetNext();
    }

    
    start_last->SetNext(end);
    end->SetPrevious(start_last);

    return start;
}

int main()
{
    Node *head = new Node(20);
    for (int i = 19; i >= 0; i--)
    {
        head->PushLast(i);
    }

    head->Print();
    Savvy(head, 10)->Print();
}