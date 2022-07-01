#include <bits/stdc++.h>
#include <bitset>

using namespace std;

template <class T = int>
class graph
{
public:
    void push(unsigned short int row, unsigned short int column, T value)
    {
        matrix[row][column] = value;
    }
    void print()
    {
        for (unsigned short int i = 0; i < CAPACITY; i++)
        {
            cout << i << ": ";
            for (unsigned short int j = 0; j < CAPACITY; j++)
            {
                cout << matrix[i][j] << "-" << j << " ";
            }
            cout << endl;
        }
    }
    void dfs_traversal(unsigned short int start, long *visited = NULL)
    {
        if (!visited)
        {
            if (matrix[start][start] != 0)
            {
                cout << matrix[start][start] << " ";
            }
            visited = new long(0);
        }
        *visited |= 1 << start;

        for (unsigned short int i = 0; i < CAPACITY; i++)
        {
            if (matrix[start][i] != 0 && ((*visited & (1 << i)) == 0))
            {
                cout << matrix[start][i] << " ";
                dfs_traversal(i, visited);
            }
        }
    }

    void bfs_traversal(unsigned short int start)
    {
        long visited = 0;
        visited |= 1 << start;

        if (matrix[start][start] != 0)
        {
            cout << matrix[start][start] << " ";
        }

        queue<unsigned short int> queue;
        queue.push(start);

        while (!queue.empty())
        {
            unsigned short int current = queue.front();
            queue.pop();
            for (unsigned short int i = 0; i < CAPACITY; i++)
            {
                if (matrix[current][i] != 0 && ((visited & (1 << i)) == 0))
                {
                    cout << matrix[current][i] << " ";
                    visited |= 1 << i;
                    queue.push(i);
                }
            }
        }
    }

    bool reachable(unsigned short int start, unsigned short int end, long *visited = NULL)
    {
        if (start == end)
            return true;

        if (!visited)
        {
            visited = new long(0);
        }
        *visited |= 1 << start;

        for (unsigned short int i = 0; i < CAPACITY; i++)
        {
            if (matrix[start][i] != 0 && ((*visited & (1 << i)) == 0))
            {
                if (i == end || reachable(i, end, visited))
                    return true;
            }
        }

        return false;
    }

private:
    static const unsigned short int CAPACITY = 10;
    T matrix[CAPACITY][CAPACITY] = {0};
};