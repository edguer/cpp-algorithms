#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

int main()
{
    tree<int> t(1);
    for (int i = 0; i < 200; i++)
    {
        t.push(i);
    }
    
    t.balance();
    list<int> *lists = t.level_lists();
    for (int i = 0; i < t.height(); i++)
    {
        cout << "level " << (i + 1) << ": ";
        list<int>::const_iterator iterator;
        for (iterator = lists[i].begin(); iterator != lists[i].end(); iterator++)
        {
            cout << *iterator << " ";
        }
        cout << endl;
    }
    
}