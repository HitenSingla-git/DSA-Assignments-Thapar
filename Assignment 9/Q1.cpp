#include <iostream>
#include <limits.h>
using namespace std;

#define MAX 20

int n;

void bfs(int adj[MAX][MAX], int start) {
    int q[MAX], front = 0, rear = 0;
    int visited[MAX] = {0};
    q[rear++] = start;
    visited[start] = 1;
    while (front < rear) {
        int u = q[front++];
        cout << u << " ";
        for (int v = 0; v < n; v++)
            if (adj[u][v] && !visited[v]) {
                visited[v] = 1;
                q[rear++] = v;
            }
    }
}

void dfsUtil(int adj[MAX][MAX], int u, int visited[MAX]) {
    visited[u] = 1;
    cout << u << " ";
    for (int v = 0; v < n; v++)
        if (adj[u][v] && !visited[v])
            dfsUtil(adj, v, visited);
}

void dfs(int adj[MAX][MAX], int start) {
    int visited[MAX] = {0};
    dfsUtil(adj, start, visited);
}

int findSet(int parent[MAX], int x) {
    while (parent[x] != x) x = parent[x];
    return x;
}

void unionSet(int parent[MAX], int a, int b) {
    int pa = findSet(parent, a);
    int pb = findSet(parent, b);
    parent[pb] = pa;
}

void kruskal(int adj[MAX][MAX]) {
    int parent[MAX];
    for (int i = 0; i < n; i++) parent[i] = i;

    int edges = 0;
    while (edges < n - 1) {
        int min_w = INT_MAX, u = -1, v = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (adj[i][j] && adj[i][j] < min_w && findSet(parent, i) != findSet(parent, j)) {
                    min_w = adj[i][j];
                    u = i; v = j;
                }
        unionSet(parent, u, v);
        cout << u << " - " << v << " : " << min_w << endl;
        edges++;
    }
}

int minKey(int key[MAX], int mstSet[MAX]) {
    int min = INT_MAX, idx = -1;
    for (int i = 0; i < n; i++)
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            idx = i;
        }
    return idx;
}

void prim(int adj[MAX][MAX]) {
    int key[MAX], parent[MAX], mstSet[MAX];
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < n - 1; i++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;
        for (int v = 0; v < n; v++)
            if (adj[u][v] && !mstSet[v] && adj[u][v] < key[v]) {
                parent[v] = u;
                key[v] = adj[u][v];
            }
    }

    for (int i = 1; i < n; i++)
        cout << parent[i] << " - " << i << " : " << adj[parent[i]][i] << endl;
}

int minDist(int dist[MAX], int visited[MAX]) {
    int min = INT_MAX, idx = -1;
    for (int i = 0; i < n; i++)
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            idx = i;
        }
    return idx;
}

void dijkstra(int adj[MAX][MAX], int src) {
    int dist[MAX], visited[MAX];
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = minDist(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < n; v++)
            if (!visited[v] && adj[u][v] && dist[u] + adj[u][v] < dist[v])
                dist[v] = dist[u] + adj[u][v];
    }

    for (int i = 0; i < n; i++)
        cout << "Node " << i << " dist = " << dist[i] << endl;
}

int main() {
    int adj[MAX][MAX], start;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    cout << "Enter start node: ";
    cin >> start;

    cout << "BFS: ";
    bfs(adj, start);
    cout << endl;

    cout << "DFS: ";
    dfs(adj, start);
    cout << endl;

    cout << "Kruskal MST:\n";
    kruskal(adj);

    cout << "Prim MST:\n";
    prim(adj);

    cout << "Dijkstra:\n";
    dijkstra(adj, start);

    return 0;
}
