#include <bits/stdc++.h>

#ifndef GRAPHMATRIX
#define GRAPHMATRIX

using namespace std;

class GraphMatrix
{
public:
    GraphMatrix()
    {
        for (int i = 0; i < VERTICES; i++)
        {
            for (int j = 0; j < VERTICES; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    void AddEdge(int vertice1, int vertice2, int distance)
    {
        if (vertice1 != vertice2 && vertice1 < VERTICES && vertice2 < VERTICES && vertice1 >= 0 && vertice2 >= 0)
        {
            matrix[vertice1][vertice2] = distance;
        }
        else
        {
            printf("Wrong vertice combination.");
        }
    }
    int GetVertices()
    {
        return VERTICES;
    }
    void Print()
    {
        cout << "   ";
        for (int i = 0; i < VERTICES; i++)
        {
            cout << " " << i;
        }
        cout << endl;

        for (int i = 0; i < VERTICES; i++)
        {
            if (i < 10)
            {
                cout << i << ": ";
            }
            else
            {
                cout << i << ":";
            }

            for (int j = 0; j < VERTICES; j++)
            {
                if (j < 10)
                {
                    cout << " ";
                }
                else
                {
                    cout << "  ";
                }

                cout << matrix[i][j];
            }
            cout << endl;
        }
    }

    void Traverse(int start_point)
    {
        bool *traversed = new bool[VERTICES];
        for (int i = 0; i < VERTICES; i++)
        {
            traversed[i] = false;
        }

        TraverseWithRecursion(start_point, traversed);
    }

    bool IsCyclic(int start_point)
    {
        bool *traversed = new bool[VERTICES];
        for (int i = 0; i < VERTICES; i++)
        {
            traversed[i] = false;
        }

        return IsCyclic(start_point, traversed);
    }

    bool IsReachable(int start_point, int end_point)
    {
        bool *traversed = new bool[VERTICES];
        for (int i = 0; i < VERTICES; i++)
        {
            traversed[i] = false;
        }

        return IsReachable(start_point, end_point, traversed);
    }

    void PrintRoutes(int start, int end)
    {
        bool *traversed = new bool[VERTICES];
        int *path = new int[VERTICES];
        for (int i = 0; i < VERTICES; i++)
        {
            traversed[i] = false;
            path[i] = -1;
        }

        int path_index = 0;
        PrintRoutes(start, end, path, path_index, traversed);
    }

    // Dijsktras algorithm
    // O(n2)
    int *GetShortestPaths(int source)
    {
        // store visited points (spt) and distances
        // set distances to max int, except for the source distance, which is 0,
        // since it is the starting poiny
        int *distances = new int[VERTICES];
        bool spt[VERTICES];
        for (int i = 0; i < VERTICES; i++)
            distances[i] = INT_MAX, spt[i] = false;

        distances[source] = 0;

        // very simple: we visit each vertex and its adjency vertices
        // then, if we find the min x j combination, we simply sum the min distance to j's, so:
        // if min distance to the source is 1, and j distance to min is 2, then the total distance is 1 + 2, so distances[j] == 3
        for (int i = 0; i < VERTICES - 1; i++)
        {
            // get min registered distance
            int min = INT_MAX, min_index;
            for (int j = 0; j < VERTICES; j++)
                if (!spt[i] && distances[j] < min)
                    min = distances[j], min_index = j;
            

            spt[min_index] = true;

            for (int j = 0; j < VERTICES; j++)
            {
                // ignore already visited vertex and where the i distance + i x j distance is less than the recorded distance
                if (!spt[j] && matrix[min_index][j] > 0 && distances[min_index] != INT_MAX && distances[min_index] + matrix[min_index][j] < distances[j])
                {
                    // new distance will be the current i distance + the one found on i x j
                    distances[j] = distances[min_index] + matrix[min_index][j];
                }
            }
        }

        return distances;
    }

private:
    static const int VERTICES = 20;
    int matrix[VERTICES][VERTICES];

    void PrintRoutes(int point, int end_point, int *path, int &path_index, bool *traversed)
    {
        // add it to traversed list and to followed path
        traversed[point] = true;
        path[path_index++] = point;

        // print if we reached it
        if (point == end_point)
        {
            for (int i = 0; i < VERTICES; i++)
            {
                if (path[i] != -1)
                {
                    cout << path[i] << " ";
                }
            }
            cout << endl;
        }
        else
        {
            for (int i = 0; i < VERTICES; i++)
            {
                if (!traversed[i] && matrix[point][i] > 0)
                {
                    PrintRoutes(i, end_point, path, path_index, traversed);
                }
            }
        }

        // go one level back on the path and clean up the current traversed point
        path_index--;
        traversed[point] = false;
    }

    void TraverseWithRecursion(int point, bool *traversed)
    {
        traversed[point] = true;
        cout << point << " ";

        for (int i = 0; i < VERTICES; i++)
        {
            if (!traversed[i] && matrix[point][i] > 0)
            {
                TraverseWithRecursion(i, traversed);
            }
        }
    }

    bool IsReachable(int point, int end_point, bool *traversed)
    {
        traversed[point] = true;
        if (point == end_point)
        {
            return true;
        }
        else
        {
            for (int i = 0; i < VERTICES; i++)
            {
                if (!traversed[i] && matrix[point][i] > 0)
                {
                    if (IsReachable(i, end_point, traversed))
                    {
                        return true;
                    }
                }
            }

            return false;
        }
    }

    bool IsCyclic(int point, bool *traversed)
    {
        if (traversed[point])
        {
            return true;
        }
        else
        {
            traversed[point] = true;

            for (int i = 0; i < VERTICES; i++)
            {
                if (matrix[point][i] > 0)
                {
                    bool is_traversed = traversed[i];
                    bool is_cyclic = IsCyclic(i, traversed);
                    if (!is_traversed && is_cyclic)
                    {
                        return true;
                    }
                    else if (is_traversed)
                    {
                        return true;
                    }
                }
            }

            return false;
        }
    }
};

#endif