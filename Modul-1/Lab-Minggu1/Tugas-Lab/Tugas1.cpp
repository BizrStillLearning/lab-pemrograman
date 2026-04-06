#include <iostream>
#include <limits>

int main() {
    int angka;
    long long total = 0;

    std::cout << "Masukkan angka (Tekan Ctrl+D di Linux/macOS atau Ctrl+Z di Windows untuk berhenti):" << std::endl;

    while (std::cin >> angka) {
        total += angka;
    }

    if (std::cin.eof()) {
        std::cout << "\nInput selesai (EOF tercapai)." << std::endl;
    } else if (std::cin.fail()) {
        std::cerr << "\nKesalahan: Input bukan merupakan integer!" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Total jumlah semua angka: " << total << std::endl;

    return 0;
}
