#include <bits/stdc++.h>
#include "utils.hpp"

using namespace std;

const unsigned short int SIZE = 5;
unsigned int image[SIZE][SIZE] = {
    {1, 0, 0, 0, 0},
    {1, 1, 0, 0, 0},
    {1, 1, 1, 0, 0}};

// [4][0] -> [0][0] -> [0][4] -> [4][4] -> [4][0]
// [4][1] -> [1][0] -> [0][3] -> [3][4] -> [4][1]
// [3][1] -> [1][1] -> [1][3] -> [3][3] -> [3][1]

//    0 1 2
// 0: 1,1,1
// 1: 1,1,0
// 2: 1,0,0

// [0][0] -> [0][2]     -> [2][2]                   -> [2][0]            -> [0][0]
// [0][1] -> [1][2]     -> [2][1]                   -> [1][0]            -> [0][1]
// [0][2] -> [2][2]     -> [2][0]                   -> [0][0]            -> [0][2]

// [1][0] -> [0][1]     -> [1][2]                   -> [2][1]            -> [1][0]
// [1][1] -> [1][1]     -> [1][1]                   -> [1][1]            -> [1][1]
// [1][2] -> [2][1]     -> [1][0]                   -> [0][1]            -> [1][2]

// [i][j] -> [j][SIZE - 1 - i] -> [SIZE - 1 - i][SIZE - 1 - j]    -> [SIZE - 1 - j][i] -> [i][j]

unsigned int new_image[SIZE][SIZE];

// O(n2)
void Rotate()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            new_image[i][SIZE - 1 - j] = image[j][i];
        }
    }
}

void RotateInPlace()
{
    for (int layer = 0; layer < SIZE / 2; layer++)
    {
        int first = layer;
        int last = SIZE - 1 - layer;
        cout << first << ":" << last << endl;
        for (int i = first; i < last; i++)
        {
            int offset = i - first;
            int top = image[first][i];
            image[first][i] = image[last - offset][first];
            cout << "image[" << first << "][" << i << "] = image[" << last - offset << "][" << first << "]" << endl;
            image[last - offset][first] = image[last][last - offset];
            image[last][last - offset] = image[i][last];
            image[i][last] = top;
        }
    }
}

int main()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }

    Run(RotateInPlace);

    cout << "-------" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
}