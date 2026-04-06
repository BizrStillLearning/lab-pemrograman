#include <iostream>
#include <iomanip>

int main() {
    int N;
    std::cout << "Masukkan jumlah elemen (N): ";
    std::cin >> N;

    int arr[N];
    int sum = 0, min, max;

    for (int i = 0; i < N; i++) {
        std::cout << "Elemen ke-" << i << ": ";
        std::cin >> arr[i];

        if (i == 0) {
            min = max = arr[i];
        } else {
            if (arr[i] < min) min = arr[i];
            if (arr[i] > max) max = arr[i];
        }
        sum += arr[i];
    }

    double avg = static_cast<double>(sum) / N;

    std::cout << "\n--- Hasil Statistik ---" << std::endl;
    std::cout << "Jumlah    : " << sum << std::endl;
    std::cout << "Rata-rata : " << std::fixed << std::setprecision(2) << avg << std::endl;
    std::cout << "Minimum   : " << min << std::endl;
    std::cout << "Maksimum  : " << max << std::endl;

    return 0;
}