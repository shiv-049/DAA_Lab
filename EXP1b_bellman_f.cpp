#include <iostream>
using namespace std;

// Structure to store an edge
struct Edge
{
    int u;   // Source vertex
    int v;   // Destination vertex
    int w;   // Weight of edge
};

int main()
{
    int n, m;

    // Input number of vertices and edges
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    Edge e[100];

    // Input edges
    cout << "Enter edges (source destination weight):" << endl;

    for (int i = 0; i < m; i++)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }

    // Input source vertex
    int source;

    cout << "Enter source vertex: ";
    cin >> source;

    // Distance table
    int distance[100][100];

    int INF = 99999;

    // Initially, all distances are infinity
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            distance[i][j] = INF;
        }
    }

    // Distance from source to itself is 0
    distance[0][source] = 0;

    // Bellman-Ford algorithm
    for (int i = 1; i < n; i++)
    {
        // Copy previous distances
        for (int j = 0; j < n; j++)
        {
            distance[i][j] = distance[i - 1][j];
        }

        // Relax all edges
        for (int j = 0; j < m; j++)
        {
            int u = e[j].u;
            int v = e[j].v;
            int weight = e[j].w;

            if (distance[i - 1][u] != INF)
            {
                if (distance[i - 1][u] + weight < distance[i][v])
                {
                    distance[i][v] =
                        distance[i - 1][u] + weight;
                }
            }
        }
    }

    // Display shortest distances
    cout << "Shortest distance:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Vertex " << i << " : ";

        if (distance[n - 1][i] == INF)
        {
            cout << "INF";
        }
        else
        {
            cout << distance[n - 1][i];
        }

        cout << endl;
    }

    return 0;
}
