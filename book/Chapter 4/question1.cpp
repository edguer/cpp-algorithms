#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

int main()
{
    tree<> t(1);
    for (size_t i = 0; i < 100; i++)
    {
        t.push(i);
    }

    t.bfs_traversal();
    cout << "Height: " << t.height() << endl;
    cout << "Balanced? " << t.balanced() << endl;

    t.balance();
    t.bfs_traversal();
    cout << "Height: " << t.height() << endl;
    cout << "Balanced? " << t.balanced() << endl;
}