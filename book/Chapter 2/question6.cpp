#include <bits/stdc++.h>
#include "Node.cpp"

using namespace std;

// O(n2), space O(2n)
Node *Naive(Node *head)
{
    Node *cur = head;
    Node *visited_list[50];
    unsigned short int count = 0;
    while (cur)
    {
        for (int i = 0; i < count; i++)
        {
            if (visited_list[i] == cur)
                return cur;
        }

        visited_list[count++] = cur;
        cur = cur->GetNext();
    }

    return NULL;
}

Node *Savvy(Node *head)
{
    // we use a slow runner and a fast runner
    // if they ever are equal, than there is a loop
    Node *slow_runner = head;
    Node *fast_runner = head->GetNext();
    if (fast_runner)
        fast_runner = fast_runner->GetNext();

    unsigned short int fast_runner_speed = 2;
    while (slow_runner && fast_runner)
    {
        if (fast_runner_speed == 1)
            cout << slow_runner->GetData() << ":" << fast_runner->GetData() << endl;

        if (slow_runner == fast_runner && fast_runner_speed == 2)
        {
            slow_runner = head;
            fast_runner_speed = 1;
        }
        else if (slow_runner == fast_runner)
        {
            return slow_runner;
        }

        slow_runner = slow_runner->GetNext();
        fast_runner = fast_runner->GetNext();
        if (fast_runner && fast_runner_speed == 2)
            fast_runner = fast_runner->GetNext();
    }

    return NULL;
}

int main()
{
    Node *head = new Node(4);
    head->PushLast(2);
    head->PushLast(8);
    head->PushLast(10);
    head->PushLast(7);
    head->PushLast(2);
    head->PushLast(8);

    // 0 1 2 3 4 5 6 7 8 9
    // 1 0 9 7 2 3 6 4 5 6
    //       
    // 01 13 25 37 49 51 63 75 87 99
    head->Print();
    // last is first 8
    head->GetNext()->GetNext()->GetNext()->GetNext()->GetNext()->SetNext(head->GetNext()->GetNext()->GetNext());

    Node *temp = Savvy(head);
    cout << temp->GetPrevious()->GetData() << ":" << temp->GetData() << ":" << temp->GetNext()->GetData() << endl;
}