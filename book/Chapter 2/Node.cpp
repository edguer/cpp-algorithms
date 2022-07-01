#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    explicit Node(int data)
    {
        this->data = data;
        next = previous = NULL;
    }
    int GetData(void)
    {
        return data;
    }
    Node *GetNext(void)
    {
        return next;
    }
    void SetNext(Node *node)
    {
        next = node;
    }
    Node *GetPrevious(void)
    {
        return previous;
    }
    void SetPrevious(Node *node)
    {
        previous = node;
    }
    void PushLast(int data)
    {
        Node *new_node = new Node(data);
        Node *node = this;
        while (node->GetNext() != NULL)
        {
            node = node->GetNext();
        }
        new_node->SetPrevious(node);
        node->SetNext(new_node);
    }
    int PopLast()
    {
        Node *node = this;
        while (node->GetNext() != NULL)
        {
            node = node->GetNext();
        }

        if (node == this)
        {
            return -1;
        }
        
        node->GetPrevious()->SetNext(NULL);
        node->SetPrevious(NULL);
        int ret = node->GetData();
        
        delete node;
        return ret; 
    }
    void Print()
    {
        Node *node = this;
        while (node)
        {
            cout << node->GetData() << " ";
            node = node->GetNext();
        }
        cout << endl;
    }
    static Node *GenerateNode()
    {
        Node *node = new Node(3);
        node->PushLast(4);
        node->PushLast(10);
        node->PushLast(6);
        node->PushLast(63);
        node->PushLast(56);
        node->PushLast(3);
        node->PushLast(0);
        node->PushLast(23);
        node->PushLast(4);
        node->PushLast(33);

        return node;
    }
private:
    Node *next, *previous;
    int data;
};

class CharNode
{
public:
    explicit CharNode(char data)
    {
        this->data = data;
        next = previous = NULL;
    }
    char GetData(void)
    {
        return data;
    }
    CharNode *GetNext(void)
    {
        return next;
    }
    void SetNext(CharNode *node)
    {
        next = node;
    }
    CharNode *GetPrevious(void)
    {
        return previous;
    }
    void SetPrevious(CharNode *node)
    {
        previous = node;
    }
    void PushLast(char data)
    {
        CharNode *new_node = new CharNode(data);
        CharNode *node = this;
        while (node->GetNext() != NULL)
        {
            node = node->GetNext();
        }
        new_node->SetPrevious(node);
        node->SetNext(new_node);
    }
    int PopLast()
    {
        CharNode *node = this;
        while (node->GetNext() != NULL)
        {
            node = node->GetNext();
        }

        if (node == this)
        {
            return -1;
        }
        
        node->GetPrevious()->SetNext(NULL);
        node->SetPrevious(NULL);
        int ret = node->GetData();
        
        delete node;
        return ret; 
    }
    void Print()
    {
        CharNode *node = this;
        while (node)
        {
            cout << node->GetData() << " ";
            node = node->GetNext();
        }
        cout << endl;
    }
private:
    CharNode *next, *previous;
    char data;
};