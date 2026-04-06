#include <iostream>

int main() {
    std::cout << "Ukuran Tipe Data Fundamental (dalam Byte):" << std::endl;
    std::cout << "char          : " << sizeof(char) << " byte" << std::endl;
    std::cout << "int           : " << sizeof(int) << " byte" << std::endl;
    std::cout << "short         : " << sizeof(short) << " byte" << std::endl;
    std::cout << "long          : " << sizeof(long) << " byte" << std::endl;
    std::cout << "long long     : " << sizeof(long long) << " byte" << std::endl;
    std::cout << "float         : " << sizeof(float) << " byte" << std::endl;
    std::cout << "double        : " << sizeof(double) << " byte" << std::endl;
    std::cout << "long double   : " << sizeof(long double) << " byte" << std::endl;
    std::cout << "bool          : " << sizeof(bool) << " byte" << std::endl;
    return 0;
}
