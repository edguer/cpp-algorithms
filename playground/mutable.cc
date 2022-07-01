#include <bits/stdc++.h>

using namespace std;

class mtest
{
public:
    void test1()
    {
        b++;
    }
    void test2() const
    {
        a++;
    }
    void test3() const
    {
        b++;
    }
private:
    int a = 0;
    int mutable b = 0;
};

int main()
{

}