#include <iostream>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    
    std::cout << "Sebelum swap: x = " << x << ", y = " << y << std::endl;
    
    swap(&x, &y);
    
    std::cout << "Setelah swap: x = " << x << ", y = " << y << std::endl;

    return 0;
}