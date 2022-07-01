#include <bits/stdc++.h>
#include "BinaryTree.h"
#include "Graph.h"
#include <bitset>

using namespace std;

void tree_test()
{
    tree<int> t(1);
    t.push(25);
    t.push(20);
    t.push(30);
    t.push(75);
    t.push(70);
    t.push(80);
    t.push(81);
    t.push(82);
    t.push(83);

    t.dfs_indorder_traversal();

    cout << "Height: " << t.height() << endl;

    t.bfs_traversal();

    t.balance();

    t.dfs_indorder_traversal();

    cout << "Height: " << t.height() << endl;

    t.bfs_traversal();
}

void graph_test()
{
    graph<char> g;
    g.push(0, 0, 'a');
    g.push(0, 4, 'b');
    g.push(4, 6, 'c');
    g.push(4, 5, 'd');
    g.push(5, 8, 'e');

    g.print();
    g.dfs_traversal(0);
    cout << endl;
    g.bfs_traversal(0);
    cout << endl;
}

int main()
{
    // long *a = new long(1);
    // std::bitset<64> x(*a << 10);
    // std::cout << x << '\n';
    graph_test();
}