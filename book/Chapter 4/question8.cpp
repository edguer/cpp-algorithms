#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

int main()
{
    long big_tree_size = 20;
    long small_tree_size = 10;
    tree<> big_tree(big_tree_size/2);
    cout << "building big tree..." << endl;
    for (unsigned int i = 0; i < big_tree_size; i++)
    {
        big_tree.push(i);
    }
    big_tree.balance();
    big_tree.bfs_traversal();

    tree<> small_tree(4);
    cout << "building small tree..." << endl;
    // for (unsigned int i = 0; i < small_tree_size; i++)
    // {
    //     small_tree.push(i);
    // }
    // small_tree.balance();
    small_tree.push(1);
    small_tree.push(7);
    small_tree.push(0);
    small_tree.push(2);
    small_tree.push(5);
    small_tree.push(80);
    // small_tree.push(0);
    small_tree.bfs_traversal();
    
    cout << "subtree? " << big_tree.subtree(&small_tree) << endl;
}