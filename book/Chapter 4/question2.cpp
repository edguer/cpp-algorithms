#include <bits/stdc++.h>
#include "Graph.h"

using namespace std;

int main()
{
    graph<> g;
    g.push(0, 1, 1);
    g.push(1, 2, 1);
    g.push(2, 3, 4);
    g.push(4, 5, 4);

    g.print();
    cout << "Reachable? " << g.reachable(4, 5) << endl;
}