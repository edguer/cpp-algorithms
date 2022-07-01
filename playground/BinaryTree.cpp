#include <bits/stdc++.h>

using namespace std;

struct Branch
{
    int data;
    Branch *left, *right;
};

class BinaryTree
{
public:
    void Add(int data)
    {
        size++;
        Branch *branch = new Branch{.data = data, .left = NULL, .right = NULL};
        if (!root)
        {
            root = branch;
            return;
        }

        //left = greater value, right lesser values
        Branch *current = root;
        while (current)
        {
            if (data > current->data)
            {
                if (!current->left)
                {
                    current->left = branch;
                    break;
                }
                current = current->left;
            }
            else
            {
                if (!current->right)
                {
                    current->right = branch;
                    break;
                }
                current = current->right;
            }
        }
    }
    void Print()
    {
        Print(root, '-');
        cout << endl;
    }
    void Balance()
    {
        int *arr = new int[size];
        unsigned short int count = 0;
        ToArrayInOrder(arr, root, &count);
        
        root = Balance(arr, 0, size - 1);
    }
    void PrintLevels()
    {
        unsigned short int height = GetHeight(root);
        for (unsigned short i = 1; i <= height; i++)
        {
            cout << i << ": ";
            PrintLevel(root, i, '-');
            cout << endl;
        }
    }
private:
    Branch *root = NULL;
    unsigned short int size = 0;
    // using deapth traversal
    void Print(Branch *branch, char side)
    {
        if (branch)
        {
            Print(branch->left, 'L');
            cout << branch->data << "(" << side << ") ";
            Print(branch->right, 'R');
        }
    }
    void ToArrayInOrder(int *arr, Branch *branch, unsigned short int *count = 0)
    {
        if (branch)
        {
            ToArrayInOrder(arr, branch->left, count);
            arr[(*count)++] = branch->data;
            ToArrayInOrder(arr, branch->right, count);
        }
    }
    Branch *Balance(int *arr, unsigned short int start, unsigned short int end)
    {
        if (end >= start)
        {
            unsigned short int middle = start + ((end - start) / 2);
            Branch *ret = new Branch{ .data = arr[middle] };

            if (end > start)
            {
                ret->left = Balance(arr, start, middle - 1);
                ret->right = Balance(arr, middle + 1, end);
            }

            return ret;
        }

        return NULL;
    }
    unsigned short int GetHeight(Branch *root)
    {
        if (root)
        {
            int left = GetHeight(root->left), right = GetHeight(root->right);
            return (left > right ? left : right) + 1;
        }
        else
        {
            return 0;
        }
    }
    // using breadth traversel
    void PrintLevel(Branch *branch, unsigned short int level, char side, Branch *parent = NULL)
    {
        if (branch)
        {
            if (level == 1)
            {
                cout << branch->data << "(" << side << "-" << (parent ? parent->data : -1) << ") ";
            }
            else
            {
                PrintLevel(branch->left, level - 1, 'L', branch);
                PrintLevel(branch->right, level - 1, 'R', branch);
            }
        }
    }
};

int main()
{
    BinaryTree tree;
    tree.Add(50);
    tree.Add(75);
    tree.Add(25);
    tree.Add(24);
    tree.Add(40);
    tree.Add(58);
    tree.Add(57);
    tree.Add(56);
    tree.Add(60);
    tree.Add(65);

    tree.Print();
    tree.Balance();
    tree.Print();
    tree.PrintLevels();
}