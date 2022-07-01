#include <bits/stdc++.h>

using namespace std;

int cache[10000][10000] = { 0 };
bool forbidden[10000][10000] = { 0 };
int count_routes(int x, int y)
{
    if ((x - 1 < 0 || y - 1 < 0) || forbidden[x - 1][y - 1]) return 0;
    else if (x - 1 == 0 && y - 1 == 0) return 1;
    else if (cache[x][y] > 0) return cache[x][y];
    else
    {   
        cache[x][y] = count_routes(x - 1, y) + count_routes(x, y - 1);
        return cache[x][y];
    }
}

int main()
{
    forbidden[0][1] = true;
    cout << "Count: " << count_routes(3, 3) << endl;
}