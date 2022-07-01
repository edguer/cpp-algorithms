#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

int main()
{
    tree<int> t(10);
    for (int i = 0; i < 20; i++)
    {
        t.push(i);
    }
    // t.left = new tree<int>(5);
    // t.right = new tree<int>(15);
    // t.right->left = new tree<int>(5);
    t.dfs_indorder_traversal();
    t.bfs_traversal();

    cout << "Is binary search tree? " << t.search_tree() << endl;
}