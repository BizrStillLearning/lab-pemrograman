#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::priority_queue<int> pq;
    std::vector<int> numbers = {45, 12, 89, 33, 71, 5, 100};

    std::cout << "--- STL Priority Queue (Descending Order) ---\n";
    std::cout << "Data asli: ";
    for (int num : numbers) {
        std::cout << num << " ";
        pq.push(num);
    }
    std::cout << "\n";

    std::cout << "Data setelah dikeluarkan dari Priority Queue:\n";
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << "\n";

    return 0;
}