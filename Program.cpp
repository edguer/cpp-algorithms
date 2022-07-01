#include "Structures/LinkedListQueue.hpp"

using namespace std;


int main()
{
    LinkedQueue q;
    int a = 1, b = 2;
    q.Enqueue(&a);
    q.Enqueue(&b);

    void* last_item = 0;
    do
    {
        last_item = q.Dequeue();
        if (last_item == 0)
        {
            break;
        }

        int int_item = *(int*)last_item;
        cout << "Item dequeued: " << int_item << std::endl;
    } while (last_item != 0);

    return 0;
}