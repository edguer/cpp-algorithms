#include <bits/stdc++.h>
#include <time.h>
#include <stdio.h>
#include <typeinfo>

using namespace std;

class employee
{
public:
    employee(string name, bool available, employee *superior)
    {
        _name = name;
        _available = available;
        _superior = superior;
    }
    string name()
    {
        return _name;
    }
    bool available()
    {
        return _available;
    }
    bool receive_call(string *call_data)
    {
        cout << _name << " received..." << endl;
        bool can_answer = rand() % 2;
        if (!can_answer || !available())
        {
            if (!_superior)
            {
                printf("Current employee cannot answer and there is no superior.\n");
                return false;
            }

            cout << "Superior is: " << _superior->position() << endl;
            return _superior->receive_call(call_data);
        }
        cout << _name << " did it!" << endl;
        return true;
    }
    virtual string position()
    {
        return "employee";
    }

private:
    string _name;
    bool _available;
    employee *_superior;
};

class manager : public employee
{
public:
    manager(string name, bool available, employee *superior) : employee(name, available, superior)
    {
    }
    virtual string position()
    {
        return "manager";
    }
};

class director : public employee
{
public:
    director(string name, bool available, employee *superior) : employee(name, available, superior)
    {
    }
    virtual string position()
    {
        return "director";
    }
};

int
main()
{
    srand(time(NULL));
    employee employees[3] =
        {
            employee("Eduardo", (bool)(rand() % 2), new manager("Márcia", false, new director("Lara", false, NULL))),
            employee("Nico", (bool)(rand() % 2), NULL),
            employee("Natália", (bool)(rand() % 2), new manager("Luciana", true, new director("Moça", false, NULL))),
        };

    string data = "asc";
    for (unsigned short int i = 0; i < 3; i++)
    {
        if (employees[i].available())
        {
            if (employees[i].receive_call(&data))
                break;
        }
    }
}