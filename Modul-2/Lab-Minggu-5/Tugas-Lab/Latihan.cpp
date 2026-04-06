#include <iostream>

int* createRange(int start, int end, int& size) {
    size = end - start + 1;
    if (size <= 0) return nullptr;

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = start + i;
    }
    return arr;
}

int main() {
    int s = 5, e = 10, n;
    int* range = createRange(s, e, n);

    if (range != nullptr) {
        std::cout << "Isi Range: ";
        for (int i = 0; i < n; i++) {
            std::cout << range[i] << " ";
        }
        std::cout << std::endl;

        delete[] range;
        range = nullptr;
    }

    return 0;
}