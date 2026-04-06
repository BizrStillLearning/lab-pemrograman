#include <iostream>

void minmax(int* arr, int n, int* mn, int* mx) {
    *mn = *mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (*(arr + i) < *mn) *mn = *(arr + i);
        if (*(arr + i) > *mx) *mx = *(arr + i);
    }
}

int main() {
    int data[] = {23, 5, 67, 12, 90, 2};
    int n = sizeof(data) / sizeof(data[0]);
    int hasilMin, hasilMax;

    minmax(data, n, &hasilMin, &hasilMax);

    std::cout << "Data: 23, 5, 67, 12, 90, 2" << std::endl;
    std::cout << "Nilai Minimum: " << hasilMin << std::endl;
    std::cout << "Nilai Maksimum: " << hasilMax << std::endl;

    return 0;
}