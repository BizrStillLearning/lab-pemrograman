#include "Database.h"
#include "Kabupaten.h"
#include "Kota.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <queue>

Database::~Database() {
    for (Region* r : records) delete r;
}

void Database::loadFromCSV(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Gagal membuka " << filename << "\n";
        return;
    }
    std::string line, field;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<std::string> fields;
        while (std::getline(ss, field, ',')) fields.push_back(field);

        if (fields.size() < 8) continue;

        int code = std::stoi(fields[0]);
        std::string type = fields[1];
        std::string name = fields[2];
        std::string prov = fields[3];
        long pop = std::stol(fields[4]);
        double area = std::stod(fields[5]);
        double hdi = std::stod(fields[6]);
        double pov = std::stod(fields[7]);

        if (type == "Kabupaten") {
            records.push_back(new Kabupaten(code, name, prov, pop, area, hdi, pov));
        } else if (type == "Kota") {
            records.push_back(new Kota(code, name, prov, pop, area, hdi, pov));
        }
    }

    if (records.empty()) {
        std::cout << "[ERROR] Gagal memuat data! File CSV tidak ditemukan atau kosong.\n";
    } else {
        std::cout << "[SUKSES] Berhasil memuat " << records.size() << " data region.\n";
    }
}

void Database::listAll() const {
    for (Region* r : records) r->displayInfo();
}

void Database::sortByCode() {
    std::sort(records.begin(), records.end(), [](Region* a, Region* b) {
        return a->getCode() < b->getCode();
    });
}

Region* Database::binarySearchByCode(int targetCode) {
    sortByCode();
    auto it = std::lower_bound(records.begin(), records.end(), targetCode,
        [](Region* r, int code) { return r->getCode() < code; });

    if (it != records.end() && (*it)->getCode() == targetCode) return *it;
    return nullptr;
}

void Database::showTopKHDI(int K, const std::string& targetProvince) {
    auto cmp = [](Region* a, Region* b) { return a->getHDI() > b->getHDI(); };
    std::priority_queue<Region*, std::vector<Region*>, decltype(cmp)> pq(cmp);

    for (Region* r : records) {
        Kabupaten* kab = dynamic_cast<Kabupaten*>(r);
        Kota* kota = dynamic_cast<Kota*>(r);
        std::string prov = kab ? kab->getProvince() : (kota ? kota->getProvince() : "");

        if (prov == targetProvince) {
            pq.push(r);
            if (pq.size() > K) pq.pop();
        }
    }

    std::vector<Region*> topRegions;
    while (!pq.empty()) {
        topRegions.push_back(pq.top());
        pq.pop();
    }
    
    std::cout << "\n--- Top " << K << " HDI di " << targetProvince << " ---\n";
    for (int i = topRegions.size() - 1; i >= 0; i--) topRegions[i]->displayInfo();
}

void Database::searchByName(const std::string& query) const {
    bool found = false;
    std::cout << "\n--- Hasil Pencarian: " << query << " ---\n";
    for (Region* r : records) {
        if (r->getName().find(query) != std::string::npos) {
            r->displayInfo();
            found = true;
        }
    }
    if (!found) std::cout << "Region tidak ditemukan.\n";
}

void Database::filterByProvince(const std::string& prov) const {
    bool found = false;
    std::cout << "\n--- Data Provinsi: " << prov << " ---\n";
    for (Region* r : records) {
        Kabupaten* kab = dynamic_cast<Kabupaten*>(r);
        Kota* kota = dynamic_cast<Kota*>(r);
        std::string p = kab ? kab->getProvince() : (kota ? kota->getProvince() : "");

        if (p == prov) {
            r->displayInfo();
            found = true;
        }
    }
    if (!found) std::cout << "Tidak ada data untuk provinsi tersebut.\n";
}

void Database::sortData() {
    std::sort(records.begin(), records.end(), [](Region* a, Region* b) {
        return a->getName() < b->getName();
    });
    std::cout << "Data berhasil diurutkan berdasarkan Nama (A-Z).\n";
}

void Database::calculateAverageDensity(const std::string& prov) const {
    double totalDensity = 0;
    int count = 0;

    for (Region* r : records) {
        Kabupaten* kab = dynamic_cast<Kabupaten*>(r);
        Kota* kota = dynamic_cast<Kota*>(r);
        std::string p = kab ? kab->getProvince() : (kota ? kota->getProvince() : "");

        if (p == prov) {
            totalDensity += r->getDensity();
            count++;
        }
    }

    if (count > 0) {
        std::cout << "\nRata-rata kepadatan penduduk di " << prov
                  << " adalah " << (totalDensity / count) << " jiwa/km2 dari "
                  << count << " region.\n";
    } else {
        std::cout << "Tidak ada data untuk provinsi tersebut.\n";
    }
}

void Database::sortByPovertyRate() {
    std::sort(records.begin(), records.end(), [](Region* a, Region* b) {
        return a->getPovertyRate() < b->getPovertyRate();
    });
    std::cout << "\nData berhasil diurutkan berdasarkan Tingkat Kemiskinan Terendah.\n";
}

