#include <iostream>
#include <vector>

void dfs(const std::vector<std::vector<int>>& adj, std::vector<bool>& visited, int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(adj, visited, v);
        }
    }
}

bool isPathExists(const std::vector<std::vector<int>>& adj, int s, int t) {
    std::vector<bool> visited(adj.size(), false);

    dfs(adj, visited, s);

    return visited[t];
}

int main() {
    int N = 5;
    std::vector<std::vector<int>> adj(N);

    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    addEdge(0, 1); addEdge(1, 2);

    addEdge(3, 4);

    std::cout << "--- Cek Keberadaan Jalur (Path Exists) ---\n";
    std::cout << "Apakah ada jalur dari 0 ke 2? "
              << (isPathExists(adj, 0, 2) ? "Ya" : "Tidak") << "\n";

    std::cout << "Apakah ada jalur dari 0 ke 4? "
              << (isPathExists(adj, 0, 4) ? "Ya" : "Tidak") << "\n";

    return 0;
}

