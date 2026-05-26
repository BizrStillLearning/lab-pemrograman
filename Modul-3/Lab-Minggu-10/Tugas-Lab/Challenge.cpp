#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

bool bisaDidistribusikan(const std::vector<int>& weights, int K, int kapasitasMaks) {
    int totalTruk = 1, muatanSaatIni = 0;

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

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (bisaDidistribusikan(weights, K, mid))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main() {
    int N, jumlahTruk;

    std::cin >> N;

    std::vector<int> barang(N);
    for (int i = 0; i < N; i++)
        std::cin >> barang[i];

    std::cin >> jumlahTruk;

    std::cout << findMinCapacity(barang, jumlahTruk);

    return 0;
}