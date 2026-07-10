#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(const vector<vector<int>>& adj, int start) {
    int N = adj.size();
    vector<bool> visited(N, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "Jejak BFS dari Vertex " << start << ": ";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << "\n";
}

int main() {
    int N = 5;

    vector<vector<int>> adj(N);

    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 4);

    for (int u = 0; u < N; u++) {
        cout << "List Vertex " << u << " terhubung dengan: ";
        for (int v : adj[u]) {
            cout << v << " ";
        }
        cout << "\n";
    }

    bfs(adj, 0);

    return 0;
}