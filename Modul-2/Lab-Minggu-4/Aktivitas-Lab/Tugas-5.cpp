#include <iostream>

void cetakNilai(int* ptr) {
    if (ptr != nullptr) {
        std::cout << "Nilai yang ditunjuk: " << *ptr << std::endl;
    } else {
        std::cout << "Peringatan: Pointer kosong (nullptr)!" << std::endl;
    }
}

int main() {
    int angka = 100;
    int* ptrValid = &angka;
    int* ptrKosong = nullptr;

    std::cout << "Mencoba ptrValid: ";
    cetakNilai(ptrValid);

    std::cout << "Mencoba ptrKosong: ";
    cetakNilai(ptrKosong);

    return 0;
}