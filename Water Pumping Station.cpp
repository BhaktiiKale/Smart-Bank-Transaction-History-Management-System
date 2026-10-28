#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

const int N = 6;

string station[N] = {
    "Pump Station A",
    "Pump Station B",
    "Pump Station C",
    "Pump Station D",
    "Pump Station E",
    "Distribution Point F"
};

int main()
{
    int graph[N][N] = {0};

    // Pipeline distances / transportation costs
    graph[0][1] = graph[1][0] = 4;
    graph[0][2] = graph[2][0] = 2;
    graph[1][2] = graph[2][1] = 1;
    graph[1][3] = graph[3][1] = 5;
    graph[2][3] = graph[3][2] = 8;
    graph[2][4] = graph[4][2] = 10;
    graph[3][4] = graph[4][3] = 2;
    graph[3][5] = graph[5][3] = 6;
    graph[4][5] = graph[5][4] = 3;

    cout << "====================================\n";
    cout << " WATER PIPELINE ROUTE OPTIMIZATION\n";
    cout << "     DIJKSTRA'S ALGORITHM\n";
    cout << "====================================\n\n";

    cout << "Available Water Stations:\n";
    for (int i = 0; i < N; i++)
        cout << i + 1 << ". " << station[i] << endl;

    int source, destination;

    cout << "\nEnter source station (1-6): ";
    cin >> source;

    cout << "Enter destination station (1-6): ";
    cin >> destination;

    if (source < 1 || source > N ||
        destination < 1 || destination > N)
    {
        cout << "\nInvalid station number!\n";
        return 0;
    }

    int dist[N], parent[N];
    bool visited[N] = {false};

    for (int i = 0; i < N; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }

    dist[source - 1] = 0;

    // Dijkstra's Algorithm
    for (int count = 0; count < N; count++)
    {
        int u = -1;

        for (int i = 0; i < N; i++)
        {
            if (!visited[i] &&
                (u == -1 || dist[i] < dist[u]))
                u = i;
        }

        if (u == -1 || dist[u] == INT_MAX)
            break;

        visited[u] = true;

        for (int v = 0; v < N; v++)
        {
            if (graph[u][v] > 0 && !visited[v])
            {
                if (dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    cout << "\n====================================\n";
    cout << "       ROUTE OPTIMIZATION RESULT\n";
    cout << "====================================\n";

    cout << "Source: " << station[source - 1] << endl;
    cout << "Destination: " << station[destination - 1] << endl;

    if (dist[destination - 1] == INT_MAX)
    {
        cout << "No route available!\n";
        return 0;
    }

    vector<int> path;
    int current = destination - 1;

    while (current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());

    cout << "\nMinimum-Cost Route:\n";
    for (int i = 0; i < (int)path.size(); i++)
    {
        cout << station[path[i]];
        if (i < (int)path.size() - 1)
            cout << " -> ";
    }

    cout << "\n\nMinimum Total Distance/Cost: "
         << dist[destination - 1] << " units\n";

    cout << "====================================\n";
    cout << "       ROUTE FOUND SUCCESSFULLY\n";
    cout << "====================================\n";

    return 0;
}
