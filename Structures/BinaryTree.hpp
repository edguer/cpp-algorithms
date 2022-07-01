#include <bits/stdc++.h>

#ifndef BINARYTREE
#define BINARYTREE

using namespace std;

class BinaryTreeNode
{
public:
    BinaryTreeNode(int val)
    {
        value = val;
    }
    int GetValue()
    {
        return value;
    }
    void SetValue(int val)
    {
        value = val;
    }
    BinaryTreeNode *GetLeft()
    {
        return left;
    }
    void SetLeft(BinaryTreeNode *node)
    {
        left = node;
    }
    BinaryTreeNode *GetRight()
    {
        return right;
    }
    void SetRight(BinaryTreeNode *node)
    {
        right = node;
    }

private:
    int value;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};

class BinaryTree
{
public:
    BinaryTree()
    {
        size = 0;
    }
    void Insert(int value)
    {
        BinaryTreeNode *new_node = new BinaryTreeNode(value);
        if (root == NULL)
        {
            root = new_node;
            size++;
        }
        else
        {
            // traverse to find where to put this value
            BinaryTreeNode *parent = root;
            BinaryTreeNode *current = root;
            do
            {
                parent = current;
                if (new_node->GetValue() > parent->GetValue())
                {
                    current = current->GetLeft();
                    if (current == NULL)
                    {
                        parent->SetLeft(new_node);
                        size++;
                        return;
                    }
                }
                else
                {
                    current = current->GetRight();
                    if (current == NULL)
                    {
                        parent->SetRight(new_node);
                        size++;
                        return;
                    }
                }
            } while (true);
        }
    }

    void Print()
    {
        if (root != NULL)
        {
            PrintWithInOrderDepthTraverse(root, -10, '0');
        }
    }

    int *ToArray()
    {
        int *ret = new int[size];
        Traverse(root, ret, 0);

        return ret;
    }

    int GetSize()
    {
        return size;
    }

    void Balance()
    {
        int *arr = new int[size];
        Traverse(root, arr, 0);
        root = Balance(arr, 0, size - 1);
    }

    int GetHeight()
    {
        return GetHeight(root);
    }

    int GetLeftHeight()
    {
        return GetHeight(root->GetLeft());
    }

    int GetRightHeight()
    {
        return GetHeight(root->GetRight());
    }

    bool IsBalanced()
    {
        int height_left = GetLeftHeight();
        int height_right = GetRightHeight();

        return abs(height_left - height_right) <= 1;
    }

    bool Search(int value)
    {
        bool found = false;

        BinaryTreeNode *node = root;
        while (node != NULL)
        {
            if (node->GetValue() == value)
            {
                found = true;
                break;
            }
            else
            {
                if (value < node->GetValue())
                {
                    node = node->GetRight();
                }
                else
                {
                    node = node->GetLeft();
                }
            }
        }

        return found;
    }

    void PrintWithBreadthTraverse()
    {
        int height = GetHeight();

        for (int i = 1; i <= height; i++)
        {
            cout << i << ":";
            PrintLevel(root, i);
            cout << endl;
        }
    }

private:
    BinaryTreeNode *root;
    int size;
    void PrintWithInOrderDepthTraverse(BinaryTreeNode *node, int parent, char side)
    {
        if (node != NULL)
        {
            PrintWithInOrderDepthTraverse(node->GetRight(), node->GetValue(), 'R');
            cout << node->GetValue() << endl;
            PrintWithInOrderDepthTraverse(node->GetLeft(), node->GetValue(), 'L');
        }
    }

    int Traverse(BinaryTreeNode *node, int *arr, int iterator = 0)
    {
        if (node != NULL)
        {
            iterator += Traverse(node->GetRight(), arr, iterator);
            arr[iterator] = node->GetValue();
            iterator++;
            iterator += Traverse(node->GetLeft(), arr, iterator);

            return iterator;
        }

        return 0;
    }

    BinaryTreeNode *Balance(int *arr, int start, int finish)
    {
        if (finish - start >= 0)
        {
            int middle = start + ((finish - start) / 2);
            BinaryTreeNode *ret = new BinaryTreeNode(arr[middle]);
            ret->SetRight(Balance(arr, start, middle - 1));
            ret->SetLeft(Balance(arr, middle + 1, finish));

            return ret;
        }
        else
        {
            return NULL;
        }
    }

    int Max(int a, int b)
    {
        return a >= b ? a : b;
    }

    int GetHeight(BinaryTreeNode *node)
    {
        if (node != NULL)
        {
            return 1 + Max(GetHeight(node->GetLeft()), GetHeight(node->GetRight()));
        }
        else
        {
            return 0;
        }
    }

    void PrintLevel(BinaryTreeNode* node, int level)
    {
        if (node != NULL)
        {
            if (level == 1)
            {
                cout << " " << node->GetValue();
            }
            else
            {
                PrintLevel(node->GetRight(), level - 1);
                PrintLevel(node->GetLeft(), level - 1);
            }
        }
    }
};

#endif