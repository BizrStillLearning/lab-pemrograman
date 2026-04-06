#include <iostream>

int main() {
    int angka = 10;
    int* ptr = &angka;

    std::cout << "Nilai awal : " << angka << std::endl;

    *ptr = 50;
    std::cout << "Nilai baru  : " << angka << std::endl;
    std::cout << "Cek via ptr : " << *ptr << std::endl;

    return 0;
}