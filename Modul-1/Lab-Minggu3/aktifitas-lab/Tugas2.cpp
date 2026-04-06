#include <iostream>
int hitungJumlahDigit(int n) {
    int jumlah = 0;
    int angkaAwal = n; 

    while (n > 0) {
        jumlah += n % 10; 
        n /= 10;          
    }
    return jumlah;
}

int main() {
    int angka = 1234;
    std::cout << "Angka: " << angka << std::endl;
    std::cout << "Jumlah Digit: " << hitungJumlahDigit(angka) << std::endl;
    return 0;
}
