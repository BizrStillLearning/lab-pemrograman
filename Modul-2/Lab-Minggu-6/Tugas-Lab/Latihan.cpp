#include <iostream>
#include <vector>

std::vector<int> merge(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result;
    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            result.push_back(a[i++]);
        } else {
            result.push_back(b[j++]);
        }
    }

    while (i < a.size()) result.push_back(a[i++]);
    while (j < b.size()) result.push_back(b[j++]);

    return result;
}

int main() {
    std::vector<int> v1 = {1, 3, 5, 7};
    std::vector<int> v2 = {2, 4, 6, 8, 10};

    std::vector<int> v3 = merge(v1, v2);

    std::cout << "Hasil Gabungan Terurut: ";
    for (int x : v3) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}