#include <iostream>
using namespace std;

int main()
{
    int n = 5;

    // Graph represented using adjacency matrix
    int graph[5][5] =
    {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int selected[5] = {0, 0, 0, 0, 0};

    int totalCost = 0;

    // Start from vertex 0
    selected[0] = 1;

    cout << "Edges in Minimum Spanning Tree:\n";

    // MST contains n-1 edges
    for (int edge = 0; edge < n - 1; edge++)
    {
        int min = 9999;
        int x = 0;
        int y = 0;

        // Find minimum edge
        for (int i = 0; i < n; i++)
        {
            if (selected[i] == 1)
            {
                for (int j = 0; j < n; j++)
                {
                    if (selected[j] == 0 && graph[i][j] != 0)
                    {
                        if (graph[i][j] < min)
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        // Add selected edge to MST
        cout << x << " - " << y
             << " = " << graph[x][y] << endl;

        totalCost = totalCost + graph[x][y];

        selected[y] = 1;
    }

    cout << "Total Cost = " << totalCost << endl;

    return 0;
}
