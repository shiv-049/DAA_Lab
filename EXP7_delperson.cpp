
#include <iostream>
using namespace std;

#define V 6

// Check whether a city can be added
bool isSafe(int city, int graph[V][V], int path[], int pos)
{
    // Check connection with previous city
    if (graph[path[pos - 1]][city] == 0)
        return false;

    // Check whether city is already visited
    for (int i = 0; i < pos; i++)
    {
        if (path[i] == city)
            return false;
    }

    return true;
}

// Find Hamiltonian Cycle
bool findCycle(int graph[V][V], int path[], int pos)
{
    // All cities visited
    if (pos == V)
    {
        // Check connection to starting city
        return (graph[path[pos - 1]][path[0]] == 1);
    }

    // Try all cities
    for (int city = 1; city < V; city++)
    {
        if (isSafe(city, graph, path, pos))
        {
            path[pos] = city;

            if (findCycle(graph, path, pos + 1))
                return true;

            // Backtracking
            path[pos] = -1;
        }
    }

    return false;
}

// Display the route
void hamiltonianCycle(int graph[V][V])
{
    int path[V];

    for (int i = 0; i < V; i++)
        path[i] = -1;

    // Start from city 0
    path[0] = 0;

    if (findCycle(graph, path, 1))
    {
        cout << "\nDelivery Route:\n";

        for (int i = 0; i < V; i++)
            cout << "City " << path[i] + 1 << " -> ";

        cout << "City " << path[0] + 1 << endl;
    }
    else
    {
        cout << "Hamiltonian Cycle does not exist!";
    }
}

int main()
{
    // Graph representing 6 cities
    int graph[V][V] = {
        {0, 1, 1, 0, 0, 1},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 1, 1, 0},
        {0, 1, 1, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {1, 0, 0, 1, 1, 0}
    };

    hamiltonianCycle(graph);

    return 0;
}
