#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

bool bisaDidistribusikan(const std::vector<int>& weights, int K, int kapasitasMaks) {
    int totalTruk = 1;
    int muatanSaatIni = 0;

    for (int w : weights) {
        if (muatanSaatIni + w > kapasitasMaks) {
            totalTruk++;
            muatanSaatIni = w;
            if (totalTruk > K) return false;
        } else {
            muatanSaatIni += w;
        }
    }
    return true;
}

int findMinCapacity(const std::vector<int>& weights, int K) {
    int low = *std::max_element(weights.begin(), weights.end());
    int high = std::accumulate(weights.begin(), weights.end(), 0);
    int jawaban = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (bisaDidistribusikan(weights, K, mid)) {
            jawaban = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return jawaban;
}

int main() {
    std::vector<int> barang = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int jumlahTruk = 5;

    int kapasitasMinimal = findMinCapacity(barang, jumlahTruk);
    std::cout << "Kapasitas minimal truk yang dibutuhkan: " << kapasitasMinimal << "\n";

    return 0;
}