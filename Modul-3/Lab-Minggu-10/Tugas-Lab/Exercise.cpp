#include <iostream>
#include <vector>

int findBound(const std::vector<int>& arr, int target, bool findFirst) {
    int low = 0, high = arr.size() - 1;
    int hasilIdx = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            hasilIdx = mid;
            if (findFirst) high = mid - 1;
            else low = mid + 1;
        }
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return hasilIdx;
}

int main() {
    std::vector<int> data = {1, 3, 5, 5, 5, 5, 67, 123};
    int target = 5;

    int pertama = findBound(data, target, true);
    int terakhir = findBound(data, target, false);

    std::cout << "Target " << target << " pertama di indeks: " << pertama << "\n";
    std::cout << "Target " << target << " terakhir di indeks: " << terakhir << "\n";

    return 0;
}