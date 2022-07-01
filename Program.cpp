// #include "Structures/GraphList.hpp"
#include "Structures/GraphMatrix.hpp"
// #include "Structures/Heap.hpp"
// #include "Algorithms/BitOperations.hpp"
//#include "Algorithms/Dijkstras.hpp"

using namespace std;


int main()
{
    GraphMatrix matrix;
    matrix.AddEdge(18, 19, 1);
    // matrix.PrintRoutes(1, 2);
    int *paths = matrix.GetShortestPaths(18);
    cout << " ---- " << endl;
    for (int i = 0; i < matrix.GetVertices(); i++)
    {
        if (paths[i] > 0 && paths[i] < INT_MAX)
            cout << i << ": " << paths[i] << endl;
    }
}