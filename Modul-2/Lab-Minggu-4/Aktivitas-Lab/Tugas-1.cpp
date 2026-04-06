#include <iostream>

int main() {
    char a = 'A';
    int b = 100;
    double c = 3.14;

    std::cout << "Alamat char   (1 byte) : " << (void*)&a << std::endl;
    std::cout << "Alamat int    (4 byte) : " << &b << std::endl;
    std::cout << "Alamat double (8 byte) : " << &c << std::endl;

    return 0;
}