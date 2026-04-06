#include <iostream>

int main() {
    int* ptr = new int;

    *ptr = 100;
    std::cout << "Nilai di Heap    : " << *ptr << std::endl;
    std::cout << "Alamat di Heap   : " << ptr << std::endl;

    delete ptr;
    ptr = nullptr;

    if (ptr == nullptr) {
        std::cout << "Verifikasi: Pointer berhasil dikosongkan (nullptr)." << std::endl;
    }

    return 0;
}