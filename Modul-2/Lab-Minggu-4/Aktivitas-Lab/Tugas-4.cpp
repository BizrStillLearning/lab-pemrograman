#include <iostream>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int* ptr = arr;

    std::cout << "Isi array menggunakan aritmatika pointer:" << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << "Elemen ke-" << i << " (Alamat: " << (ptr + i) << ") = " << *(ptr + i) << std::endl;
    }

    return 0;
}