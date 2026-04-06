#include <iostream>
#include <cmath> // Untuk std::abs
#include <cstdint>

int main() {
    uint32_t a = 500;
    uint32_t b = 100;

    // uint32_t hasilSalah = a - b; // Akan terjadi underflow!

    long long selisih = static_cast<long long>(a) - static_cast<long long>(b);
    
    long long hasilAbsolut = std::abs(selisih);

    std::cout << "Nilai A    : " << a << std::endl;
    std::cout << "Nilai B    : " << b << std::endl;
    std::cout << "Selisih Abs: " << hasilAbsolut << std::endl;

    return 0;
}
