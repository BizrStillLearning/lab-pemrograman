#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>


int main() {
    int sizes[] = {100, 1000, 10000, 100000};
    std::cout << "Ukuran Larik\tInsertion Sort (ms)\tMerge Sort (ms)\n";

    for (int size : sizes) {
        std::vector<int> base(size), arr;
        for (int i = 0; i < size; i++) base[i] = rand() % 100000;

        double tInsertion = 0;
        if (size <= 10000) {
            arr = base;
            auto start = std::chrono::high_resolution_clock::now();
            auto end = std::chrono::high_resolution_clock::now();
            tInsertion = std::chrono::duration<double, std::nano>(end - start).count();
        }

        arr = base;
        auto start = std::chrono::high_resolution_clock::now();
        auto end = std::chrono::high_resolution_clock::now();
        double tMerge = std::chrono::duration<double, std::nano>(end - start).count();

        std::cout << size << "\t\t";
        if (size > 10000) std::cout << "Skipped (>10s)\t\t";
        else std::cout << tInsertion << " ms\t\t";
        std::cout << tMerge << " ms\n";
    }
    return 0;
}