#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main() {
    std::string kalimat;
    std::cout << "Masukkan satu kalimat: ";
    std::getline(std::cin, kalimat);

    std::stringstream ss(kalimat);
    std::string kata;
    std::vector<std::string> daftarKataUnik;
    std::vector<int> frekuensi;

    while (ss >> kata) {
        bool ditemukan = false;
        for (int i = 0; i < daftarKataUnik.size(); i++) {
            if (daftarKataUnik[i] == kata) {
                frekuensi[i]++;
                ditemukan = true;
                break;
            }
        }

        if (!ditemukan) {
            daftarKataUnik.push_back(kata);
            frekuensi.push_back(1);
        }
    }

    std::cout << "\n--- Hasil Analisis Kata ---" << std::endl;
    for (int i = 0; i < daftarKataUnik.size(); i++) {
        std::cout << "'" << daftarKataUnik[i] << "' muncul " << frekuensi[i] << " kali" << std::endl;
    }

    return 0;
}