#include <bits/stdc++.h>
#include "Node.cpp"

using namespace std;

// O(n + n/2)
bool IsPalindrome(CharNode *head)
{
    int length = 1;
    CharNode *last = head;
    while (last->GetNext())
    {
        last = last->GetNext();
        length++;
    }

    CharNode *first = head;
    for (unsigned short int i = 0; i < (length / 2) + 1; i++)
    {
        cout << i << ": " << first->GetData() << " - " << last->GetData() << endl;
        if (first->GetData() != last->GetData())
        {
            return false;
        }

        first = first->GetNext();
        last = last->GetPrevious();
    }
    
    return true;
}

// getting the middle point like this would allow to find if it is a palindrome by using a stack:
// we slow->GetPrevious() would give the middle point, and a stack we have stored all visited items on the top of 
// it in reverse other. Next thing you do is iterate through the rest of the linked list and compare each item with
// the top of the stack. It will have O(n), but space complexity goes to O(n + n/2)
CharNode* GetMiddleElement(CharNode *head)
{
    CharNode *slow = head, *fast = head;
    unsigned short int middle = 0;
    while (fast)
    {
        middle++;
        slow = slow->GetNext();
        fast = fast->GetNext();
        if (fast)
            fast = fast->GetNext();
    }

    cout << slow->GetPrevious()->GetData() << "-" << middle << endl;
    return slow->GetPrevious();
}

int main()
{
    // a palindrome is simetric, so a0 == an-1, a1 == an-2 and so on, except for the middle letter
    // its length is always odd
    // so we can simply have two runners: one from the end of it, another from the begining, and compare letter until n/2 +1

    CharNode *node = new CharNode('r');
    node->PushLast('e');
    node->PushLast('v');
    node->PushLast('i');
    node->PushLast('v');
    node->PushLast('e');
    node->PushLast('r');

    GetMiddleElement(node);

    cout << IsPalindrome(node) << endl;
}