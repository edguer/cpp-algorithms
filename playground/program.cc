#include <bits/stdc++.h>

using namespace std;

template <class T> bool DoStuff(T a, T b)
{
    return a == b;
}

template <class T=char> class MyClass
{
public:
    int val = 0;
    const bool DoStuff(T a, T b)
    {
        val = 60;
        return a == b;
    }
    const bool DoStuff(T a, T b) const
    {
        cout << "const call" << endl;
        return a == b;
    }
    MyClass& operator = (const MyClass &source)
    {
        cout << source.val << endl;
        return *this;
    }
};

int main()
{
    MyClass<> a;
    a.val = 50;

    const MyClass<> b;

    a.DoStuff('a', 'b');
    bool c = b.DoStuff('a', 'b');
    c = false;
}