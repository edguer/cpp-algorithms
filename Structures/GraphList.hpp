#include <bits/stdc++.h>
#include "LinkedList.hpp"
#include "Queue.hpp"

#ifndef GRAPHLIST
#define GRAPHLIST

using namespace std;

class GraphList
{
public:
    GraphList(int vertices)
    {
        this->vertices = vertices;
        list = new LinkedList[vertices];
    }
    void AddEdge(int vertice1, int vertice2)
    {
        if (vertice1 != vertice2 && vertice1 < this->vertices && vertice2 < this->vertices && vertice1 >= 0 && vertice2 >= 0)
        {
            list[vertice1].AddFirst(vertice2);
        }
        else
        {
            printf("Wrong vertice combination.");
        }
    }
    void Print()
    {
        cout << "   ";
        for (int i = 0; i < this->vertices; i++)
        {
            cout << " " << i;
        }
        cout << endl;

        for (int i = 0; i < this->vertices; i++)
        {
            if (i < 10)
            {
                cout << i << ": ";
            }
            else
            {
                cout << i << ":";
            }

            for (int j = 0; j < this->vertices; j++)
            {
                if (j < 10)
                {
                    cout << " ";
                }
                else
                {
                    cout << "  ";
                }

                if (list[i].Contains(j))
                {
                    cout << "X";
                }
                else
                {
                    cout << "-";
                }
            }
            cout << endl;
        }
    }

    void Traverse(int start_point)
    {
        bool *traversed = new bool[vertices];
        for (int i = 0; i < this->vertices; i++)
        {
            traversed[i] = false;
        }

        traversed[start_point] = true;

        Queue queue(this->vertices);
        queue.Enqueue(start_point);

        while (!queue.IsEmpty())
        {
            int point = queue.Dequeue();
            cout << point << " ";

            int *connected_vertices = list[point].GetAll();
            for (int i = 0; i < list[point].GetSize(); i++)
            {
                if (!traversed[connected_vertices[i]])
                {
                    traversed[connected_vertices[i]] = true;
                    queue.Enqueue(connected_vertices[i]);
                }
            }
        }
    }

    void TraverseWithRecursion(int start_point)
    {
        bool *traversed = new bool[vertices];
        for (int i = 0; i < this->vertices; i++)
        {
            traversed[i] = false;
        }

        TraverseWithRecursion(start_point, traversed);
    }

private:
    LinkedList *list;
    int vertices;

    void TraverseWithRecursion(int point, bool *traversed)
    {
        traversed[point] = true;
        cout << point << " ";

        int *connected_vertices = list[point].GetAll();
        for (int i = 0; i < list[point].GetSize(); i++)
        {
            if (!traversed[connected_vertices[i]])
            {
                TraverseWithRecursion(connected_vertices[i], traversed);
            }
        }
    }
};

#endif