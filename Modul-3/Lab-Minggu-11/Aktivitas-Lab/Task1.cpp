#include <iostream>
#include <vector>
#include <cstdlib>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void verifyAndPrint(std::vector<int>& arr, int size) {
    mergeSort(arr, 0, arr.size() - 1);
    bool terurut = true;
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) terurut = false;
    }
    std::cout << "Ukuran " << size << " -> Status: " << (terurut ? "BERHASIL TERURUT" : "GAGAL") << "\n";
}

int main() {
    int sizes[] = {10, 100, 1000};
    for (int size : sizes) {
        std::vector<int> arr(size);
        for (int i = 0; i < size; i++) arr[i] = rand() % 5000;
        verifyAndPrint(arr, size);
    }
    return 0;
}