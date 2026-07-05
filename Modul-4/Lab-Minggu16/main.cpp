#include <iostream>
#include <limits>
#include "Database.h"

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    Database db;
    db.loadFromCSV("C:/Users/AbidzarDzakwanSahudi/CLionProjects/kuliah/lab-pemrograman/Modul-4/Lab-Minggu16/data/regions.csv");

    int choice = 0;
    do {
        std::cout << "\n=== Regional Statistics Explorer ===\n"
                  << "1. Tampilkan Semua Region\n"
                  << "2. Cari Region (Binary Search via Code)\n"
                  << "3. Tampilkan Top-K HDI di suatu Provinsi\n"
                  << "9. Keluar\n"
                  << "Pilih: ";

        if (!(std::cin >> choice)) {
            std::cout << "Input tidak valid. Harap masukkan angka.\n";
            clearInputBuffer();
            continue;
        }

        if (choice == 1) {
            db.listAll();
        }
        else if (choice == 2) {
            int code;
            std::cout << "Masukkan 4-digit Kode BPS: ";
            if (!(std::cin >> code)) {
                std::cout << "Kode harus berupa angka.\n";
                clearInputBuffer();
            } else {
                Region* result = db.binarySearchByCode(code);
                if (result) result->displayInfo();
                else std::cout << "Region dengan kode tersebut tidak ditemukan.\n";
            }
        }
        else if (choice == 3) {
            int k;
            std::string prov;
            std::cout << "Berapa region (K)? ";
            if (!(std::cin >> k)) {
                std::cout << "Jumlah K harus berupa angka.\n";
                clearInputBuffer();
                continue;
            }
            std::cout << "Provinsi (contoh: Jawa Timur): ";
            std::cin.ignore();
            std::getline(std::cin, prov);

            if (k > 0 && !prov.empty()) {
                db.showTopKHDI(k, prov);
            } else {
                std::cout << "Input K atau Provinsi tidak valid.\n";
            }
        }
    } while (choice != 9);

    std::cout << "Menutup program dan membersihkan memori...\n";
    return 0;
}


