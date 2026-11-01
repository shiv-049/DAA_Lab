
#include <iostream>
using namespace std;

#define V 5
#define INF 9999

int main()
{
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int selected[V] = {0};
    int edges = 0;
    int totalCost = 0;

    selected[0] = 1;

    cout << "Roads selected for Minimum Spanning Tree:\n";

    while (edges < V - 1)
    {
        int min = INF;
        int x = 0, y = 0;

        for (int i = 0; i < V; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (!selected[j] && graph[i][j] != 0)
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

        cout << x << " - " << y
             << " : " << graph[x][y] << " km" << endl;

        totalCost += graph[x][y];
        selected[y] = 1;
        edges++;
    }

    cout << "\nMinimum Total Road Length = "
         << totalCost << " km" << endl;

    return 0;
}
