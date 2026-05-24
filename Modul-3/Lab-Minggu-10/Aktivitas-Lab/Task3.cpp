#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> data = {1, 2, 4, 4, 4, 4, 5, 7, 9};
    int target = 4;

    auto low = std::lower_bound(data.begin(), data.end(), target);

    auto up = std::upper_bound(data.begin(), data.end(), target);

    int count = up - low;

    std::cout << "Elemen " << target << " muncul sebanyak: " << count << " kali.\n";

    return 0;
}