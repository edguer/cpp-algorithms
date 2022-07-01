#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

[event_source(native)]
class source
{
public:
    __event void on_click(string value);
};

[event_receiver(native)]
class destination
{
public:
    destination(source* s)
    {
        __hook (&source::on_click, s, &destination::handle_click);
    }
    void handle_click(string value)
    {
        cout << "Got event: " << value << endl;
    }
};

int main()
{
    source s;
    destination d(&s);

    __raise s.on_click("TEST!");
}