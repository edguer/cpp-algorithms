#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

int main()
{
    tree<long> t(-5);
    for (long i = -4; i < 10; i++)
    {
        t.push(i);
    }
    t.balance();
    t.bfs_traversal();
    t.print_paths_sum(8);
}