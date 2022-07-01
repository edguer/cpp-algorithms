#include <bits/stdc++.h>
#include "Node.cpp"

using namespace std;

//O(n), space O(n + 4)
void NotMemoryEfficient(Node *node)
{
    Node *cur_node = node;
    long visited_nodes = 0;
    while (cur_node)
    {
        if ((visited_nodes & (1 << cur_node->GetData())) > 0)
        {
            if (cur_node->GetPrevious())
                cur_node->GetPrevious()->SetNext(cur_node->GetNext());

            if (cur_node->GetNext())
                cur_node->GetNext()->SetPrevious(cur_node->GetPrevious());

            Node *next = cur_node->GetNext();
            delete cur_node;
            cur_node = next;
        }
        else
        {
            visited_nodes |= 1 << cur_node->GetData();
            cur_node = cur_node->GetNext();
        }
    }
}

//O(4n - (2n - 2)) -> O(2n + 2)
void MemoryEfficient(Node *node)
{
    Node *head = node;
    Node *cur_node = node;
    while (cur_node)
    {
        Node *compare_node = cur_node->GetNext();
        while (compare_node)
        {
            if (compare_node->GetData() == cur_node->GetData())
            {
                if (compare_node->GetPrevious())
                    compare_node->GetPrevious()->SetNext(compare_node->GetNext());

                if (compare_node->GetNext())
                    compare_node->GetNext()->SetPrevious(compare_node->GetPrevious());

                Node *next = compare_node->GetNext();
                delete compare_node;
                compare_node = next;
            }
            compare_node = compare_node->GetNext();
        }

        cur_node = cur_node->GetNext();
    }
}

int main()
{
    Node *node = Node::GenerateNode();

    node->Print();
    MemoryEfficient(node);
    node->Print();
}