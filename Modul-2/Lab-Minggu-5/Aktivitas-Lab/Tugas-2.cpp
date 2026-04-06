#include <iostream>

int main() {
    int N;
    std::cout << "Masukkan jumlah elemen (N): ";
    std::cin >> N;

    int* arr = new int[N];

    for (int i = 0; i < N; i++) {
        arr[i] = i * i;
    }

    std::cout << "Isi array dinamis: ";
    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    arr = nullptr;

    return 0;
}