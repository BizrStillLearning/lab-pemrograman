#include <iostream>
#include <cmath>

int main() {
    double a = 0.3;
    double b = 0.2;
    double c = 0.3;
    double hasil = a + b;

    std::cout << "Hasil 0.1 + 0.2 : " << hasil << std::endl;
    std::cout << "Apakah (0.1 + 0.2 == 0.3)? " << (hasil == c ? "Ya" : "Tidak") << std::endl;

    double epsilon = 1e-9;
    bool isSama = std::fabs(hasil - c) < epsilon;

    std::cout << "Hasil dengan Epsilon: " << (isSama ? "Sama (Ditoleransi)" : "Tetap Berbeda") << std::endl;

    return 0;
}
