#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

void countingSort(std::vector<int>& arr, int K) {
    std::vector<int> count(K + 1, 0);
    std::vector<int> output(arr.size());

    for (int x : arr) count[x]++;
    for (int i = 1; i <= K; i++) count[i] += count[i - 1];
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    arr = output;
}

int main() {
    int N = 1000000;
    int K = 100;
    std::vector<int> base(N), arr;

    for (int i = 0; i < N; i++) base[i] = rand() % (K + 1);

    arr = base;
    auto start = std::chrono::high_resolution_clock::now();
    countingSort(arr, K);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Durasi Counting Sort: " 
              << std::chrono::duration<double, std::milli>(end - start).count() << " ms\n";

    arr = base;
    start = std::chrono::high_resolution_clock::now();
    std::sort(arr.begin(), arr.end());
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Durasi std::sort     : " 
              << std::chrono::duration<double, std::milli>(end - start).count() << " ms\n";

    return 0;
}