/**
 * Implement the Binary Tree and: DFS and BFS, balancing
 * */

#include <bits/stdc++.h>

using namespace std;

template <class T = long>
class tree
{
public:
    tree<T> *left, *right;
    T data;

    tree(T data)
    {
        this->data = data;
        left = right = NULL;
    }
    void push(T data)
    {
        tree<T> *new_tree = new tree<T>(data);

        tree<T> *current = this;
        while (current)
        {
            if (data <= current->data)
            {
                if (current->left)
                    current = current->left;
                else
                {
                    current->left = new_tree;
                    break;
                }
            }
            else
            {
                if (current->right)
                    current = current->right;
                else
                {
                    current->right = new_tree;
                    break;
                }
            }
        }

        count++;
    }
    void dfs_indorder_traversal()
    {
        dfs_indorder_traversal(this, '-');
        cout << endl;
    }
    unsigned long height()
    {
        return height(this);
    }
    void bfs_traversal()
    {
        unsigned long levels = height();
        for (long i = 1; i <= levels; i++)
        {
            cout << i << ": ";
            bfs_traversal(this, i, '-');
            cout << endl;
        }
    }
    list<T> *level_lists()
    {
        unsigned long levels = height();
        list<T> *ret = new list<T>[levels];
        for (long i = 1; i <= levels; i++)
        {
            list<T> lst;
            level_list(this, i, &lst);
            ret[i - 1] = lst;
        }

        return ret;
    }
    void balance()
    {
        T *arr = to_array();

        tree<T> *balanced_tree = build_inorder(arr, 0, size() - 1);
        this->data = balanced_tree->data;
        this->left = balanced_tree->left;
        this->right = balanced_tree->right;
    }
    T *to_array()
    {
        T *arr = new T[size()];
        unsigned long it = 0;
        dfs_indorder_traversal(this, arr, &it);

        return arr;
    }
    unsigned long size()
    {
        return count + 1;
    }
    bool balanced()
    {
        return height(this, true) >= 0;
    }
    bool search_tree()
    {
        return search_tree(this->left, LONG_MIN) && search_tree(this->right, LONG_MIN);
    }
    T common_ancestor(T a, T b)
    {
        tree<T> *ancestor = common_ancestor(this, a, b);
        if (ancestor)
            return ancestor->data;
        else
            return 0;
    }
    // follow the top of the tree using bfs, compare using dfs
    // O(n * k), worst scenario, where n = size of big tree and k = size of small tree
    // but most of the time if will be O(n + k) or even less, depending on where the subtree is
    // Time complexity is O(n + k)
    // An alternative would be converting both trees to ordered arrays and compare then, it would be
    // O(2n + k) most of the times, but it would consume 2n in memory. For a big tree, it is not viable
    bool subtree(tree<T> *branch)
    {
        queue<tree<T> *> q;
        q.push(this);

        while (!q.empty())
        {
            tree<T> *current = q.front();
            q.pop();
            if (current->data == branch->data && equal(current, branch))
                return true;

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }

        return false;
    }
    void print_paths_sum(long sum)
    {
        list<T> q;
        long current_sum = 0;
        print_paths_sum(this, sum, q, current_sum);
    }

private:
    unsigned long count = 0;
    void print_paths_sum(tree<T> *root, long sum, list<T> q, long current_sum)
    {
        if (root)
        {
            q.push_back(root->data);
            current_sum += root->data;
            if (current_sum == sum)
            {
                list<long>::const_iterator iterator;
                cout << "Sum matches the following path: ";
                for (iterator = q.begin(); iterator != q.end(); iterator++)
                {
                    cout << *iterator << " ";
                }
                cout << endl;
                current_sum -= q.front();
                q.pop_front();
            }
            // else if (current_sum > sum)
            // {
            //     current_sum -= q.front();
            //     q.pop_front();
            // }

            print_paths_sum(root->left, sum, q, current_sum);
            print_paths_sum(root->right, sum, q, current_sum);

            current_sum -= q.back();
            q.pop_back();
        }
    }
    bool equal(tree<T> *fulltree, tree<T> *subtree)
    {
        if (fulltree && subtree)
            return equal(fulltree->left, subtree->left) && fulltree->data == subtree->data && equal(fulltree->right, subtree->right);
        else if (subtree && !fulltree)
            return false;
        else
            return true;
    }
    bool search_tree(tree<T> *branch, T parent_data)
    {
        return (!branch || (search_tree(branch->left, branch->data) && search_tree(branch->right, branch->data) && parent_data <= branch->data));
    }
    void dfs_indorder_traversal(tree<T> *tree, char side)
    {
        if (tree)
        {
            dfs_indorder_traversal(tree->left, 'L');
            cout << tree->data << "(" << side << ") ";
            dfs_indorder_traversal(tree->right, 'R');
        }
    }
    void dfs_indorder_traversal(tree<T> *tree, T *arr, unsigned long *it)
    {
        if (tree)
        {
            dfs_indorder_traversal(tree->left, arr, it);
            arr[(*it)++] = tree->data;
            dfs_indorder_traversal(tree->right, arr, it);
        }
    }
    long height(tree<T> *tree, bool stop_unbalanced = false)
    {
        if (!tree)
            return 0;
        else
        {
            unsigned long left = height(tree->left, stop_unbalanced);
            if (stop_unbalanced && left < 0)
                return -1;

            unsigned long right = height(tree->right, stop_unbalanced);
            if (stop_unbalanced && right < 0)
                return -1;

            if (stop_unbalanced && abs((long)(left - right)) > 1)
            {
                return -1;
            }

            return (left > right ? left : right) + 1;
        }
    }
    void bfs_traversal(tree<T> *tree, unsigned long level, char side)
    {
        if (tree)
        {
            if (level == 1)
            {
                cout << tree->data << "(" << side << ") ";
            }
            else
            {
                bfs_traversal(tree->left, level - 1, 'L');
                bfs_traversal(tree->right, level - 1, 'R');
            }
        }
    }
    tree<T> *common_ancestor(tree<T> *root, T a, T b)
    {
        if (!root)
            return NULL;
        if (root->data == a || root->data == b)
            return root;

        bool a_on_left = parent(root->left, a);
        bool b_on_left = parent(root->left, b);

        if (a_on_left != b_on_left)
            return root;
        else
            return common_ancestor(a_on_left ? root->left : root->right, a, b);
    }
    bool parent(tree<T> *root, T value)
    {
        if (!root)
            return false;
        if (root->data == value)
            return true;
        return parent(root->left, value) || parent(root->right, value);
    }
    void level_list(tree<T> *tree, unsigned long level, list<T> *list)
    {
        if (tree)
        {
            if (level == 1)
            {
                list->push_back(tree->data);
            }
            else
            {
                level_list(tree->left, level - 1, list);
                level_list(tree->right, level - 1, list);
            }
        }
    }
    tree<T> *build_inorder(T *arr, long start, long end)
    {
        tree<T> *ret = NULL;
        if (end >= start)
        {
            long middle = start + ((end - start) / 2);
            ret = new tree<T>(arr[middle]);

            ret->left = build_inorder(arr, start, middle - 1);
            ret->right = build_inorder(arr, middle + 1, end);
        }

        return ret;
    }
};