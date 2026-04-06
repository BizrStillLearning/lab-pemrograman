#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {10, 20, 30, 40, 50};

    std::cout << "Vector awal : ";
    for (int x : v) std::cout << x << " ";
    std::cout << std::endl;

    int n = v.size();
    for (int i = 0; i < n / 2; i++) {
        int temp = v[i];
        v[i] = v[n - 1 - i];
        v[n - 1 - i] = temp;
    }

    std::cout << "Setelah dibalik: ";
    for (int x : v) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}