#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int maxCrossingSum(const std::vector<int>& arr, int low, int mid, int high) {
    int sum = 0, left_sum = INT_MIN;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > left_sum) left_sum = sum;
    }
    sum = 0; int right_sum = INT_MIN;
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > right_sum) right_sum = sum;
    }
    return left_sum + right_sum;
}

int maxSubarraySumDC(const std::vector<int>& arr, int low, int high) {
    if (low == high) return arr[low];

    int mid = low + (high - low) / 2;

    return std::max({
        maxSubarraySumDC(arr, low, mid),
        maxSubarraySumDC(arr, mid + 1, high),
        maxCrossingSum(arr, low, mid, high)
    });
}

int main() {
    std::vector<int> data = {-2, -5, 6, -2, -3, 1, 5, -6};
    int max_sum = maxSubarraySumDC(data, 0, data.size() - 1);
    std::cout << "Maksimum Subarray Sum (D&C): " << max_sum << "\n";
    return 0;
}