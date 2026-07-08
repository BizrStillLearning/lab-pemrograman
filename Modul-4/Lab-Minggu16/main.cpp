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
                  << "  1. Tampilkan Semua Region\n"
                  << "  2. Cari Region berdasarkan Nama\n"
                  << "  3. Filter Region berdasarkan Provinsi\n"
                  << "  4. Urutkan Data berdasarkan Nama (A-Z)\n"
                  << "  5. Cari Region Cepat (Binary Search via Kode BPS)\n"
                  << "  6. Tampilkan Top-K HDI di suatu Provinsi (Priority Queue)\n"
                  << "  7. Hitung Rata-rata Kepadatan Penduduk per Provinsi\n"
                  << "  8. Urutkan berdasarkan Tingkat Kemiskinan Terendah\n"
                  << "  9. Keluar\n"
                  << "Pilih menu (1-9): ";

        if (!(std::cin >> choice)) {
            std::cout << "Input tidak valid. Harap masukkan angka.\n";
            clearInputBuffer();
            continue;
        }

        if (choice == 1) {
            db.listAll();
        }
        else if (choice == 2) {
            std::string query;
            std::cout << "Masukkan potongan nama daerah (contoh: Sura): ";
            std::cin.ignore();
            std::getline(std::cin, query);
            db.searchByName(query);
        }
        else if (choice == 3) {
            std::string prov;
            std::cout << "Masukkan nama provinsi (contoh: Jawa Timur): ";
            std::cin.ignore();
            std::getline(std::cin, prov);
            db.filterByProvince(prov);
        }
        else if (choice == 4) {
            db.sortData();
            std::cout << "Tekan 1 untuk melihat hasilnya.\n";
        }
        else if (choice == 5) {
            int code;
            std::cout << "Masukkan 4-digit Kode BPS (contoh: 3578): ";
            if (!(std::cin >> code)) {
                std::cout << "Kode harus berupa angka.\n";
                clearInputBuffer();
            } else {
                Region* result = db.binarySearchByCode(code);
                if (result) result->displayInfo();
                else std::cout << "Region dengan kode BPS tersebut tidak ditemukan.\n";
            }
        }
        else if (choice == 6) {
            int k;
            std::string prov;
            std::cout << "Berapa jumlah wilayah teratas yang ingin dilihat (K)? ";
            if (!(std::cin >> k)) {
                std::cout << "Input harus berupa angka.\n";
                clearInputBuffer();
                continue;
            }
            std::cout << "Di provinsi apa (contoh: Jawa Timur)? ";
            std::cin.ignore();
            std::getline(std::cin, prov);

            if (k > 0 && !prov.empty()) db.showTopKHDI(k, prov);
            else std::cout << "Input tidak valid.\n";
        }
        else if (choice == 7) {
            std::string prov;
            std::cout << "Masukkan nama provinsi: ";
            std::cin.ignore();
            std::getline(std::cin, prov);
            db.calculateAverageDensity(prov);
        }
        else if (choice == 8) {
            db.sortByPovertyRate();
            std::cout << "Tekan 1 untuk melihat hasilnya (dari kemiskinan terendah).\n";
        }
        else if (choice != 9) {
            std::cout << "Pilihan tidak tersedia. Silakan coba lagi.\n";
        }

    } while (choice != 9);

    std::cout << "Menutup program. Memori telah dibersihkan.\n";
    return 0;
}