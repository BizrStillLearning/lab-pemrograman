#include <iostream>

void tampilkanHeader() {
    std::cout << "===========================\n";
    std::cout << "   PROGRAM HITUNG PERSEGI  \n";
    std::cout << "===========================\n";
}
int ambilInputSisi() {
    int s;
    std::cout << "Masukkan panjang sisi: ";
    std::cin >> s;
    return s;
}
int hitungLuas(int sisi) { return sisi * sisi; }
void tampilkanHasil(int luas) {
    std::cout << "Luas persegi tersebut adalah: " << luas << "\n";
    std::cout << "===========================\n";
}

int main() {
    tampilkanHeader();
    int sisi = ambilInputSisi();
    int luas = hitungLuas(sisi);
    tampilkanHasil(luas);
    return 0;
}
