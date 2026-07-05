#include <iostream>
#include <vector>

bool isCyclicUtil(const std::vector<std::vector<int>>& adj, std::vector<bool>& visited, int u, int parent) {
    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            if (isCyclicUtil(adj, visited, v, u)) {
                return true;
            }
        }
        else if (v != parent) {
            return true;
        }
    }
    return false;
}

bool hasCycle(const std::vector<std::vector<int>>& adj) {
    std::vector<bool> visited(adj.size(), false);

    for (int i = 0; i < adj.size(); i++) {
        if (!visited[i]) {
            if (isCyclicUtil(adj, visited, i, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int N = 5;

    std::vector<std::vector<int>> adjWithCycle(N);
    adjWithCycle[0].push_back(1); adjWithCycle[1].push_back(0);
    adjWithCycle[1].push_back(2); adjWithCycle[2].push_back(1);
    adjWithCycle[2].push_back(0); adjWithCycle[0].push_back(2);

    std::vector<std::vector<int>> adjNoCycle(N);
    adjNoCycle[0].push_back(1); adjNoCycle[1].push_back(0);
    adjNoCycle[1].push_back(2); adjNoCycle[2].push_back(1);

    std::cout << "--- Pendeteksi Siklus Graf Tak Berarah ---\n";
    std::cout << "Graf 1 (Ada Siklus)   : " << (hasCycle(adjWithCycle) ? "Terdeteksi Siklus!" : "Aman") << "\n";
    std::cout << "Graf 2 (Tanpa Siklus) : " << (hasCycle(adjNoCycle) ? "Terdeteksi Siklus!" : "Aman") << "\n";

    return 0;
}