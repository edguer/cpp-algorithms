#include <bits/stdc++.h>

#ifndef HASHTABLE
#define HASHTABLE

using namespace std;

class DataItem
{
public:
    DataItem()
    {
    }
    DataItem(int key, string value)
    {
        this->key = key;
        this->value = value;
    }
    int GetKey()
    {
        return key;
    }
    string GetValue()
    {
        return value;
    }

private:
    int key;
    string value;
};

class HashTable
{
public:
    HashTable(int capacity)
    {
        this->capacity = capacity;
        typedef DataItem *DataItemPtr;
        items = new DataItemPtr[capacity];
        for (int i = 0; i < capacity; i++)
        {
            items[i] = NULL;
        }
    }
    int GetHash(int key)
    {
        return ((key % 10) * 10) - 10;
    }
    void Insert(DataItem *item)
    {
        int hash = GetHash(item->GetKey());
        while (items[hash] != NULL)
        {
            hash++;
        }
        items[hash] = item;
    }
    DataItem *Get(int key)
    {
        int hash = GetHash(key);
        DataItem *ret;
        while (items[hash] != NULL)
        {
            if (items[hash]->GetKey() == key)
            {
                ret = items[hash];
                break;
            }
            else
            {
                hash++;
            }
        }

        return ret;
    }
    void Print()
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << i << " - " << (items[i] == NULL ? "NULL" : items[i]->GetValue()) << endl;
        }
    }

private:
    int capacity;
    DataItem **items;
};

#endif