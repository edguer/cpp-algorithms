#include <bits/stdc++.h>
using namespace std;
#ifndef UTILS
#define UTILS

void Run(void(*func)())
{
    auto start = chrono::high_resolution_clock::now(); 
    func();
    auto stop = chrono::high_resolution_clock::now();
    cout << "Execution time: " << chrono::duration_cast<chrono::microseconds>(stop - start).count() << endl;
}

#endif