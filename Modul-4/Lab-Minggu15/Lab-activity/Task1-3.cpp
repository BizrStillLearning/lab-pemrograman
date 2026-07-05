#include <iostream>
#include <vector>
#include <queue>
#include <stack>

// --- Task 2: BFS (Breadth-First Search) ---
void bfs(const std::vector<std::vector<int>>& adj, int start) {
    std::vector<bool> visited(adj.size(), false);
    std::queue<int> q;
    
    visited[start] = true;
    q.push(start);
    
    while (!q.empty()) {
        int u = q.front(); 
        q.pop();
        std::cout << u << " ";
        
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

// --- Task 3: DFS (Depth-First Search) Rekursif ---
void dfsRecursive(const std::vector<std::vector<int>>& adj, std::vector<bool>& visited, int u) {
    visited[u] = true;
    std::cout << u << " ";
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfsRecursive(adj, visited, v);
        }
    }
}

// --- Task 3: DFS Iteratif (Menggunakan Stack) ---
void dfsIterative(const std::vector<std::vector<int>>& adj, int start) {
    std::vector<bool> visited(adj.size(), false);
    std::stack<int> s;
    
    s.push(start);
    
    while (!s.empty()) {
        int u = s.top(); 
        s.pop();
        
        if (!visited[u]) {
            visited[u] = true;
            std::cout << u << " ";
            
            for (auto it = adj[u].rbegin(); it != adj[u].rend(); ++it) {
                if (!visited[*it]) {
                    s.push(*it);
                }
            }
        }
    }
}

int main() {
    // --- Task 1: Build the Graph (Sesuai Figure 5) ---
    int N = 4;
    std::vector<std::vector<int>> adj(N);
    
    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };
    
    addEdge(0, 1); addEdge(0, 2); addEdge(1, 2);
    addEdge(1, 3); addEdge(2, 3);
    
    std::cout << "--- Task 2: BFS Traversal ---\n";
    std::cout << "Mulai dari vertex 0: ";
    bfs(adj, 0);
    std::cout << "\n\n";
    
    std::cout << "--- Task 3: DFS Traversal ---\n";
    std::vector<bool> visited(N, false);
    std::cout << "DFS Rekursif (Mulai dari 0): ";
    dfsRecursive(adj, visited, 0);
    std::cout << "\n";
    
    std::cout << "DFS Iteratif (Mulai dari 0): ";
    dfsIterative(adj, 0);
    std::cout << "\n";

    return 0;
}