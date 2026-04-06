#include <iostream>
#include <vector>

int main() {
    std::vector<int> daftar = {4, 5, 4, 1, 5, 4, 9, 1};
    std::vector<int> unik;
    std::vector<int> frekuensi;

    for (int angka : daftar) {
        bool ditemukan = false;
        
        for (int i = 0; i < unik.size(); i++) {
            if (unik[i] == angka) {
                frekuensi[i]++;
                ditemukan = true;
                break;
            }
        }

        if (!ditemukan) {
            unik.push_back(angka);
            frekuensi.push_back(1);
        }
    }

    std::cout << "Nilai Unik & Frekuensi:" << std::endl;
    for (int i = 0; i < unik.size(); i++) {
        std::cout << unik[i] << " muncul " << frekuensi[i] << " kali" << std::endl;
    }

    return 0;
}