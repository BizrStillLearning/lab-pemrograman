#include <iostream>
#include <vector>

std::vector<int> mergeSortedVectors(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result;
    result.reserve(a.size() + b.size());
    size_t i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) result.push_back(a[i++]);
        else result.push_back(b[j++]);
    }
    while (i < a.size()) result.push_back(a[i++]);
    while (j < b.size()) result.push_back(b[j++]);

    return result;
}

int main() {
    std::vector<int> v1 = {1, 4, 7}, v2 = {2, 3, 5, 8};
    std::vector<int> gabungan = mergeSortedVectors(v1, v2);

    std::cout << "Hasil Penggabungan Linier: ";
    for (int x : gabungan) std::cout << x << " ";
    std::cout << "\n";
    return 0;
}