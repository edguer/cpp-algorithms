#include <bits/stdc++.h>

#include <bits/stdc++.h>
#include <cmath>

#ifndef GRAPH
#define GRAPH

using namespace std;

namespace contoso
{
    class graph
    {
    public:
        graph(unsigned int capacity)
        {
            size = capacity;
            matrix = new int *[size];
            for (unsigned int i = 0; i < size; i++)
            {
                matrix[i] = new int[size];
                for (unsigned int j = 0; j < size; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        void push(unsigned int a, unsigned int b, unsigned int distance)
        {
            matrix[a][b] = distance;
        }

        void print()
        {
            cout << "   ";
            for (unsigned int i = 0; i < size; i++)
            {
                cout << i << " ";
            }
            cout << endl;

            for (unsigned int i = 0; i < size; i++)
            {
                cout << i << ": ";
                for (unsigned int j = 0; j < size; j++)
                {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }

        void dfs(unsigned int point)
        {
            bool *visited = new bool[size];
            for (unsigned int i = 0; i < size; i++)
            {
                visited[i] = false;
            }

            stack<unsigned int> stck;
            stck.push(point);

            while (!stck.empty())
            {
                unsigned int p = stck.top();
                stck.pop();

                if (!visited[p])
                {
                    cout << p << " ";
                    visited[p] = true;
                    for (unsigned int i = 0; i < size; i++)
                    {
                        if (matrix[p][i] > 0)
                        {
                            stck.push(i);
                        }
                    }
                }
            }
        }

        void bfs(unsigned int point)
        {
            bool *visited = new bool[size];
            for (unsigned int i = 0; i < size; i++)
            {
                visited[i] = false;
            }

            queue<unsigned int> q;
            q.push(point);

            while (!q.empty())
            {
                unsigned int p = q.front();
                q.pop();

                if (!visited[p])
                {
                    cout << p << " ";
                    visited[p] = true;
                    for (unsigned int i = 0; i < size; i++)
                    {
                        if (matrix[p][i] > 0)
                        {
                            q.push(i);
                        }
                    }
                }
            }
        }

    private:
        int **matrix;
        unsigned int size;
    };
}

#endif