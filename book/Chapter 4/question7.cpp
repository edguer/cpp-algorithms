#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

int main()
{
    tree<> t(11);
    for (unsigned short int i = 0; i < 10; i++)
    {
        t.push(i);
    }
    t.balance();
    t.bfs_traversal();

    cout << "Ancestor: " << t.common_ancestor(7, 11) << endl;
}