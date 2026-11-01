
#include <iostream>
using namespace std;

#define V 5

// Check whether a vertex can be added to the cycle
bool isSafe(int v, int graph[V][V], int path[], int pos)
{
    // Check if the vertex is adjacent to the previous vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if the vertex is already included
    for (int i = 0; i < pos; i++)
    {
        if (path[i] == v)
            return false;
    }

    return true;
}

// Recursive function to find Hamiltonian Cycle
bool hamiltonianUtil(int graph[V][V], int path[], int pos)
{
    // If all vertices are included
    if (pos == V)
    {
        // Check if last vertex connects to first vertex
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;

        return false;
    }

    // Try different vertices
    for (int v = 1; v < V; v++)
    {
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;

            // Recursively check remaining vertices
            if (hamiltonianUtil(graph, path, pos + 1))
                return true;

            // Backtracking
            path[pos] = -1;
        }
    }

    return false;
}

// Function to find Hamiltonian Cycle
void hamiltonianCycle(int graph[V][V])
{
    int path[V];

    for (int i = 0; i < V; i++)
        path[i] = -1;

    // Start from vertex 0
    path[0] = 0;

    if (hamiltonianUtil(graph, path, 1))
    {
        cout << "Hamiltonian Cycle exists:\n";

        for (int i = 0; i < V; i++)
            cout << path[i] << " -> ";

        cout << path[0] << endl;
    }
    else
    {
        cout << "No Hamiltonian Cycle exists.";
    }
}

int main()
{
    int graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamiltonianCycle(graph);

    return 0;
}
