#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    int prev_capacity = 0;

    std::cout << "Memulai pengamatan pertumbuhan vector..." << std::endl;
    std::cout << "Elemen Ke-\tKapasitas Baru" << std::endl;
    std::cout << "-------------------------------" << std::endl;

    for (int i = 1; i <= 33; i++) {
        v.push_back(i);
        
        if (v.capacity() != prev_capacity) {
            std::cout << i << "\t\t" << v.capacity() << std::endl;
            prev_capacity = v.capacity();
        }
    }

    return 0;
}