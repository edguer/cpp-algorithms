#include <bits/stdc++.h>
#include "Node.cpp"

using namespace std;

void NaiveDelete(Node *node)
{
    if (!node)
    {
        return;
    }
    
    if (node->GetNext())
        node->GetNext()->SetPrevious(node->GetPrevious());
    
    if (node->GetPrevious())
        node->GetPrevious()->SetNext(node->GetNext());

    delete node;
}
int main()
{
    Node *head = Node::GenerateNode();
    head->Print();
    // delete last
    Node *cur = head;
    while (cur)
    {
        if (!cur->GetNext())
        {
            NaiveDelete(cur);
            break;
        }
        cur = cur->GetNext();
    }
    // NaiveDelete(head->GetNext()->GetNext());
    head->Print();
}