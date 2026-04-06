#include <iostream>

void reverseArray(int* arr, int n) {
    int* start = arr;
    int* end = arr + (n - 1);

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int n = 5;

    reverseArray(data, n);

    std::cout << "Array setelah dibalik: ";
    for (int i = 0; i < n; i++) {
        std::cout << *(data + i) << " ";
    }
    std::cout << std::endl;

    return 0;
}