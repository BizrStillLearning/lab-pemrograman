#include <iostream>

int main() {
    int* ptr = new int(100);
    
    std::cout << "Nilai sebelum delete : " << *ptr << " (Alamat: " << ptr << ")" << std::endl;

    delete ptr; 

    std::cout << "Nilai setelah delete (BAHAYA!): " << *ptr << std::endl;

    ptr = nullptr;
    std::cout << "Setelah set nullptr  : Pointer aman (0)" << std::endl;

    return 0;
}