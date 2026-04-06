#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string kalimat;

    std::cout << "Masukkan satu kalimat: ";
    std::getline(std::cin, kalimat);

    int panjang = kalimat.length();
    std::cout << "Panjang kalimat : " << panjang << " karakter" << std::endl;

    int jumlahSpasi = 0;
    for (char c : kalimat) {
        if (c == ' ') jumlahSpasi++;
    }
    std::cout << "Jumlah spasi    : " << jumlahSpasi << std::endl;

    std::string kalimatTerbalik = kalimat;
    std::reverse(kalimatTerbalik.begin(), kalimatTerbalik.end());
    std::cout << "Kalimat terbalik: " << kalimatTerbalik << std::endl;

    return 0;
}