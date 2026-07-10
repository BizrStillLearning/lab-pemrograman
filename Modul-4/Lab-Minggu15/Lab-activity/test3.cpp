#include <iostream>
using namespace std;

struct Edge {
    int tujuan;
    Edge* next;
};

struct Vertex {
    char nama;
    Edge* head;
};

int main() {
    Vertex graph[5] = {
        {'A', NULL},
        {'B', NULL},
        {'C', NULL},
        {'D', NULL},
        {'E', NULL}
    };

    auto addEdge = [&](int asal, int tujuan) {
        Edge* baru = new Edge;
        baru->tujuan = tujuan;
        baru->next = graph[asal].head;
        graph[asal].head = baru;
    };

    addEdge(0, 1); addEdge(1, 0);
    addEdge(0, 2); addEdge(2, 0);
    addEdge(0, 3); addEdge(3, 0);
    addEdge(1, 3); addEdge(3, 1);
    addEdge(2, 3); addEdge(3, 2);
    addEdge(2, 4); addEdge(4, 2);

    for (int i = 0; i < 5; i++) {
        cout << graph[i].nama << " -> ";

        Edge* temp = graph[i].head;
        while (temp != NULL) {
            cout << graph[temp->tujuan].nama << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    return 0;
}