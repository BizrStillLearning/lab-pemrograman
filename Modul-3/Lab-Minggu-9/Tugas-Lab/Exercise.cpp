#include <iostream>
#include <vector>
#include <algorithm>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    std::cout << "Masukkan jumlah elemen (N): ";
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    if (n <= 1000) {
        std::cout << "Menggunakan Insertion Sort manual...\n";
        insertionSort(arr);
    } else {
        std::cout << "Menggunakan std::sort bawaan...\n";
        std::sort(arr.begin(), arr.end());
    }

    std::cout << "Hasil Terurut: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}