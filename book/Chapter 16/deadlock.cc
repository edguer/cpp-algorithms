#include <bits/stdc++.h>

using namespace std;

int main()
{
    mutex m1, m2;
    thread t1([&m1, &m2]
    {
        printf("acquiring m1\n");
        m1.lock();
        this_thread::sleep_for(chrono::milliseconds(10));
        printf("acquiring m2\n");
        m2.lock();
    });
    thread t2([&m1, &m2]
    {
        printf("acquiring m2\n");
        m2.lock();
        this_thread::sleep_for(chrono::milliseconds(10));
        printf("acquiring m1\n");
        m1.lock();
    });

    t1.join(), t2.join();
}