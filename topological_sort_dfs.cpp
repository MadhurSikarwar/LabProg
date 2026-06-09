#include <iostream>

using namespace std;

int graph[100][100] = {0};
bool visited[100] = {false};
int my_stack[100];
int top = -1;

void push(int val) {
    top++;
    my_stack[top] = val;
}

void dfs(int node, int V) {
    visited[node] = true;

    for (int i = 0; i < V; i++) {
        if (graph[node][i] == 1 && visited[i] == false) {
            dfs(i, V);
        }
    }

    push(node);
}

void topologicalSort(int V) {
    for (int i = 0; i < V; i++) {
        if (visited[i] == false) {
            dfs(i, V);
        }
    }

    while (top != -1) {
        cout << my_stack[top] << " ";
        top--;
    }
    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    
    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter the directed edges (u v) one by one:\n";
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
    }

    cout << "\nTopological Sort of the graph using DFS:\n";
    topologicalSort(V);

    return 0;
}
