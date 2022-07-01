using namespace std;

struct node
{
    int data;
    node *next;
    node *previous;
};

class LinkedList
{
private:
    node *head, *tail;
    int count = 0;

public:
    LinkedList()
    {
    }
    //O(1)
    void AddFirst(int data)
    {
        node *new_member = new node;
        new_member->data = data;

        if (head == NULL)
        {
            head = tail = new_member;
        }
        else
        {
            new_member->next = head;
            head = new_member;
            head->next->previous = head;
            if (head->next->next == NULL)
            {
                tail = head->next;
            }
        }

        count++;
    }
    void AddLast(int data)
    {
        node *new_member = new node;
        new_member->data = data;

        if (head == NULL)
        {
            head = tail = new_member;
        }
        else
        {
            new_member->previous = tail;
            tail = new_member;
            tail->previous->next = tail;
            if (tail->previous->previous == NULL)
            {
                head = tail->previous;
            }
        }
    }
    bool AddAfter(int data, int new_data)
    {
        node *current_member = head;
        node *desired_member = NULL;
        while (current_member != NULL)
        {
            if (current_member->data == data)
            {
                desired_member = current_member;
                break;
            }

            current_member = current_member->next;
        }

        if (desired_member == NULL)
        {
            return false;
        }
        else
        {
            node *new_member = new node;
            new_member->data = new_data;
            new_member->previous = desired_member;
            new_member->next = desired_member->next;

            desired_member->next->previous = new_member;
            desired_member->next = new_member;

            return true;
        }
    }
    int GetSize()
    {
        return count;
    }
    //O(N)
    void Display()
    {
        node *current_member = head;
        while (current_member != NULL)
        {
            cout << "current: " << current_member->data << " next: " << (current_member->next == NULL ? -1 : current_member->next->data) << " previous: " << (current_member->previous == NULL ? -1 : current_member->previous->data) << endl;
            current_member = current_member->next;
        }

        if (tail != NULL)
        {
            cout << "tail " << tail->data << " next: " << (tail->next == NULL ? -1 : tail->next->data) << " previous: " << (tail->previous == NULL ? -1 : tail->previous->data) << endl;
        }
    }
    bool Contains(int value)
    {
        node *node = head;
        while (node != NULL)
        {
            if (node->data == value)
            {
                return true;
            }
            else
            {
                node = node->next;
            }
        }

        return false;
    }
    int *GetAll()
    {
        int *ret = new int[count];

        node *node = head;
        int i = 0;
        while (node != NULL)
        {
            ret[i++] = node->data;
            node = node->next;
        }

        return ret;
    }
};