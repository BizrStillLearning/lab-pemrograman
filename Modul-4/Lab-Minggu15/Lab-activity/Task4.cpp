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

int countComponents(const std::vector<std::vector<int>>& adj) {
    std::vector<bool> visited(adj.size(), false);
    int components = 0;

    for (int u = 0; u < adj.size(); u++) {
        if (!visited[u]) {
            dfs(adj, visited, u);
            components++;
        }
    }
    return components;
}

int main() {
    int N = 6;
    std::vector<std::vector<int>> adj(N);

    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    addEdge(0, 1);
    addEdge(1, 2);

    addEdge(3, 4);
    addEdge(4, 5);

    std::cout << "--- Penghitungan Connected Components ---\n";
    int total = countComponents(adj);
    std::cout << "Total komponen yang terputus di dalam graf: " << total << "\n";

    return 0;
}