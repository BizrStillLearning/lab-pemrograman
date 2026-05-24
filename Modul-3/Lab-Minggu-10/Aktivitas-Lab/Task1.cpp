#include <iostream>
#include <vector>
#include <chrono>

bool linearSearch(const std::vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return true;
    }
    return false;
}

bool binarySearch(const std::vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return true;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int main() {
    int N = 1000000;
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) arr[i] = i;

    int target = N - 1;

    auto start = std::chrono::high_resolution_clock::now();
    linearSearch(arr, target);
    auto end = std::chrono::high_resolution_clock::now();
    double tLinear = std::chrono::duration<double, std::milli>(end - start).count();

    start = std::chrono::high_resolution_clock::now();
    binarySearch(arr, target);
    end = std::chrono::high_resolution_clock::now();
    double tBinary = std::chrono::duration<double, std::milli>(end - start).count();

    std::cout << "--- Hasil Pengamatan Waktu (N = 1.000.000) ---\n";
    std::cout << "Linear Search : " << tLinear << " ms\n";
    std::cout << "Binary Search : " << tBinary << " ms\n";

    return 0;
}