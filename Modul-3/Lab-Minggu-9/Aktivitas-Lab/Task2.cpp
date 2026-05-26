#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>


void generateRandomArray(std::vector<int>& arr, int size) {
    arr.clear();
    for (int i = 0; i < size; i++) arr.push_back(rand() % 10000);
}

int main() {
    int sizes[] = {1000, 5000, 10000};
    
    std::cout << "Ukuran Data\tBubble (ms)\tSelection (ms)\tInsertion (ms)\n";

    for (int size : sizes) {
        std::vector<int> base, arr;
        generateRandomArray(base, size);

        arr = base;
        auto start = std::chrono::high_resolution_clock::now();
        auto end = std::chrono::high_resolution_clock::now();
        double tBubble = std::chrono::duration<double, std::nano>(end - start).count();

        arr = base;
        start = std::chrono::high_resolution_clock::now();
        end = std::chrono::high_resolution_clock::now();
        double tSelection = std::chrono::duration<double, std::nano>(end - start).count();

        arr = base;
        start = std::chrono::high_resolution_clock::now();
        end = std::chrono::high_resolution_clock::now();
        double tInsertion = std::chrono::duration<double, std::nano>(end - start).count();

        std::cout << size << "\t\t" << (int)tBubble << "\t\t" << (int)tSelection << "\t\t" << (int)tInsertion << "\n";
    }
    return 0;
}