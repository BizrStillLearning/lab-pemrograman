#include <iostream>
long long faktorialIteratif(int n) {
    long long hasil = 1;
    for (int i = 1; i <= n; i++) {
        hasil *= i;
    }
    return hasil;
}

long long faktorialRekursif(int n) {
    if (n <= 1) return 1; 
    int variabelLokal;
    std::cout << "Kedalaman n=" << n << " di alamat: " << &variabelLokal << std::endl;
    return n * faktorialRekursif(n - 1); 
}

int main() {
    int angka = 5;
    
    std::cout << "--- Hasil Faktorial " << angka << " ---" << std::endl;
    std::cout << "Iteratif: " << faktorialIteratif(angka) << std::endl;
    std::cout << "Rekursif: " << std::endl;
    std::cout << "Total Rekursif: " << faktorialRekursif(angka) << std::endl;
    
    return 0;
}
