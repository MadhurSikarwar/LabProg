#include <iostream>

using namespace std;

int minDistance(int dist[], bool visited[], int V) {
    int min = 999999;
    int min_index = -1;

    for (int v = 0; v < V; v++) {
        if (visited[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[100][100], int src, int V) {
    int dist[100];
    bool visited[100];

    for (int i = 0; i < V; i++) {
        dist[i] = 999999;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        if(u == -1) break;
        
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (visited[v] == false && graph[u][v] != 0 && dist[u] != 999999 && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "\nVertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++) {
        if(dist[i] == 999999)
            cout << i << " \t " << "INF" << endl;
        else
            cout << i << " \t " << dist[i] << endl;
    }
}

int main() {
    int V, src;
    int graph[100][100];

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter the adjacency matrix (" << V << "x" << V << "):\n";
    cout << "(Enter 0 if there is no edge)\n";
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter source vertex (0 to " << V-1 << "): ";
    cin >> src;
    
    dijkstra(graph, src, V);
    return 0;
}
