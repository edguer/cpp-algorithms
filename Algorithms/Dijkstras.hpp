#include <bits/stdc++.h>

#ifndef Dijkstras
#define Dijkstras

using namespace std;

class Edge
{
public:
    Edge(int source, int destination, int distance)
    {
        this->source = source;
        this->destination = destination;
        this->distance = distance;
    }
    int GetSource(void)
    {
        return source;
    }
    int GetDestination(void)
    {
        return destination;
    }
    int GetDistance(void)
    {
        return distance;
    }
    void SetDistance(int distance)
    {
        this->distance = distance;
    }

private:
    int source;
    int destination;
    int distance;
};

class LinkedListNode
{
public:
    LinkedListNode(Edge *edge)
    {
        next = NULL;
        previous = NULL;
        this->edge = edge;
    }
    LinkedListNode *GetNext(void)
    {
        return next;
    }
    void SetNext(LinkedListNode *node)
    {
        next = node;
    }
    LinkedListNode *GetPrevious(void)
    {
        return previous;
    }
    void SetPrevious(LinkedListNode *node)
    {
        previous = node;
    }
    Edge *GetEdge()
    {
        return edge;
    }

private:
    LinkedListNode *next;
    LinkedListNode *previous;
    Edge *edge;
};

class LinkedList
{
public:
    LinkedList()
    {
        first = last = NULL;
    }
    void AddFirst(Edge *edge)
    {
        if (first == NULL)
        {
            first = last = new LinkedListNode(edge);
            first->SetNext(last);
            last->SetPrevious(first);
            last->SetNext(NULL);
        }
        else
        {
            LinkedListNode *node = new LinkedListNode(edge);
            node->SetPrevious(last);
            last->SetNext(node);
            last = last->GetNext();
            last->SetNext(NULL);
        }

        size++;
    }
    void Print()
    {
        LinkedListNode *node = first;
        LinkedListNode *last = NULL;
        while (node != NULL && node != last)
        {
            cout << node->GetEdge()->GetDestination() << " ";
            last = node;
            node = node->GetNext();
        }
    }

    Edge** ToArray()
    {
        typedef Edge * EdgePtr;
        Edge ** ret = new EdgePtr[size];
        LinkedListNode *node = first;
        int count = 0;
        while (node != NULL)
        {
            ret[count++] = node->GetEdge();
            node = node->GetNext();
        }

        return ret;
    }

    int GetSize()
    {
        return size;
    }

private:
    LinkedListNode *first;
    LinkedListNode *last;
    int size = 0;
};

class MinHeap
{
public:
    MinHeap(int capacity)
    {
        typedef Edge *EdgePtr;
        heap = new EdgePtr[capacity];
        for (int i = 0; i < capacity; i++)
        {
            heap[i] = NULL;
        }

        index = 0;
        this->capacity = capacity;
    }

    void Add(Edge *edge)
    {
        int current_index = index;
        heap[index++] = edge;

        BubbleUp(current_index);
    }

    void BubbleUp(int current_index)
    {
        int parent_index = GetParent(current_index);
        while (current_index > 0 && heap[parent_index]->GetDistance() > heap[current_index]->GetDistance())
        {
            Swap(current_index, parent_index);

            current_index = parent_index;
            parent_index = GetParent(current_index);
        }
    }

    Edge *TakeMin()
    {
        Edge *ret = heap[0];
        heap[0] = heap[--index];

        SinkDown(0);

        return ret;
    }

    void Print()
    {
        for (int i = 0; i < index; i++)
        {
            cout << "(" << i << ", " << heap[i]->GetSource() << ", " << heap[i]->GetDestination() << ", " << heap[i]->GetDistance() << ") ";
        }
        
    }

    bool IsEmpty()
    {
        return index == 0;
    }

    void UpdateDistance(int source, int destination, int distance)
    {
        if (index == 0)
        {
            printf("Heap is empty");
            return;
        }
        int updated_index = UpdateDistance(0, source, destination, distance);
        BubbleUp(updated_index);
    }
private:
    Edge **heap;
    int capacity, index;

    int UpdateDistance(int i, int source, int destination, int distance)
    {
        if (i >= index)
        {
            return -1;
        }

        Edge *edge = heap[i];
        if (edge->GetSource() == source && edge->GetDestination() == destination)
        {
            edge->SetDistance(distance);
            return i;
        }
        else
        {
            int ret = UpdateDistance(GetLeft(i), source, destination, distance);
            if (ret == -1)
            {
                ret = UpdateDistance(GetRight(i), source, destination, distance);
            }

            return ret;
        }
    }

    int GetParent(int index)
    {
        return index < 1 ? 0 : (index - 1) / 2;
    }

    int GetLeft(int index)
    {
        return (2*index) + 1;
    }

    int GetRight(int index)
    {
        return (2*index) + 2;
    }

    void Swap(int index1, int index2)
    {
        Edge *temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }

    void SinkDown(int i)
    {
        if (i < this->index)
        {
            int left_index = GetLeft(i);
            int right_index = GetRight(i);
            int smallest_distance = i;

            if (left_index < this->index && heap[left_index]->GetDistance() < smallest_distance)
            {
                cout << "left is smallest " << left_index << endl;
                smallest_distance = left_index;
            }

            if (right_index < this->index && heap[right_index]->GetDistance() < smallest_distance)
            {
                cout << "right is smallest " << right_index << endl;
                smallest_distance = right_index;
            }

            if (smallest_distance != i)
            {
                Swap(smallest_distance, i);
                SinkDown(smallest_distance);
            }
        }
    }
};

class Graph
{
public:
    Graph(int vertices)
    {
        typedef LinkedList * LinkedListPtr;
        list = new LinkedListPtr[vertices];
        for (int i = 0; i < vertices; i++)
        {
            list[i] = new LinkedList;
        }

        this->vertices = vertices;
    }
    void Add(int source, int destination, int distance)
    {
        Edge *edge = new Edge(source, destination, distance);
        list[source]->AddFirst(edge);
    }
    void Print()
    {
        for (int i = 0; i < vertices; i++)
        {
            cout << i << ": ";
            list[i]->Print();
            cout << endl;
        }
    }
    int *GetShortestPaths(int point)
    {
        bool spt[vertices];
        MinHeap heap(vertices);
        int * distances = new int[vertices];
        for (int i = 0; i < vertices; i++)
        {
            int distance = i == 0 ? 0 : INT_MAX;
            heap.Add(new Edge(point, i, distance));
            distances[i] = distance;
            spt[i] = false;
        }
        
        while (!heap.IsEmpty())
        {
            Edge *vertex = heap.TakeMin();
            cout << "vertex " << vertex->GetDistance() << endl;
            spt[vertex->GetSource()] = true;

            LinkedList *linked_list = list[vertex->GetSource()];
            Edge **edges = linked_list->ToArray();
            for (int i = 0; i < linked_list->GetSize(); i++)
            {
                if (!spt[edges[i]->GetDestination()])
                {
                    int new_distance = distances[vertex->GetSource()] + edges[i]->GetDistance();
                    cout << "dest " << edges[i]->GetDestination() << " new dist " << new_distance << endl;
                    if (distances[vertex->GetSource()] > new_distance)
                    {
                        heap.UpdateDistance(vertex->GetSource(), edges[i]->GetDestination(), new_distance);
                        distances[vertex->GetSource()] = new_distance;
                    }
                }
            }
        }

        return distances;
    }
private:
    LinkedList **list;
    int vertices;
};

#endif