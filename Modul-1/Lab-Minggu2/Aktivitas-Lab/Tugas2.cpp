#include <iostream>
#include <climits> 

int main() {
    int nilaiMaks = INT_MAX;
    std::cout << "Nilai INT_MAX         : " << nilaiMaks << std::endl;
    nilaiMaks = nilaiMaks + 1;
    std::cout << "Nilai setelah + 1     : " << nilaiMaks << std::endl;
    return 0;
}
