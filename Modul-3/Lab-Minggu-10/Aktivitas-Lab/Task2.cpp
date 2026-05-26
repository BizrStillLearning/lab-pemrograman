#include <iostream>
#include <vector>

int recursiveBinarySearch(const std::vector<int>& arr, int low, int high, int target) {
    if (low > high) return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) return mid;

    if (arr[mid] < target) {
        return recursiveBinarySearch(arr, mid + 1, high, target);
    } else {
        return recursiveBinarySearch(arr, low, mid - 1, target);
    }
}

int main() {
    std::vector<int> data = {10, 23, 45, 70, 89, 100, 150};
    int n = data.size();

    int targets[5] = {45, 10, 150, 50, 200};

    std::cout << "--- Uji Rekursif Binary Search ---\n";
    for (int t : targets) {
        int hasil = recursiveBinarySearch(data, 0, n - 1, t);
        if (hasil != -1) {
            std::cout << "Target " << t << " Ditemukan pada indeks " << hasil << "\n";
        } else {
            std::cout << "Target " << t << " Tidak Ditemukan\n";
        }
    }
    return 0;
}