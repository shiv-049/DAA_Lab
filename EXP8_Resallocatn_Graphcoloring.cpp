
#include <iostream>
using namespace std;

#define V 6
#define M 4

// Check whether resource can be assigned
bool isSafe(int task, int graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++)
    {
        if (graph[task][i] == 1 && color[i] == c)
            return false;
    }

    return true;
}

// Graph coloring using backtracking
bool graphColoring(int graph[V][V], int color[], int task)
{
    // All tasks are assigned
    if (task == V)
        return true;

    // Try all 4 resources
    for (int c = 1; c <= M; c++)
    {
        if (isSafe(task, graph, color, c))
        {
            color[task] = c;

            if (graphColoring(graph, color, task + 1))
                return true;

            // Backtracking
            color[task] = 0;
        }
    }

    return false;
}

int main()
{
    // Conflict graph of 6 tasks
    int graph[V][V] = {
        {0, 1, 1, 0, 0, 1},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {1, 0, 0, 1, 1, 0}
    };

    int color[V] = {0};

    if (graphColoring(graph, color, 0))
    {
        cout << "Conflict-free Resource Allocation:\n";

        for (int i = 0; i < V; i++)
        {
            cout << "Task " << i + 1
                 << " -> Resource " << color[i] << endl;
        }
    }
    else
    {
        cout << "No valid resource allocation exists!";
    }

    return 0;
}
