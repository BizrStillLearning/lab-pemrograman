#include <iostream>

int main() {
    int matriks[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int sumDiagonal = 0;

    std::cout << "Matriks 3x3:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matriks[i][j] << " ";
            
            if (i == j) {
                sumDiagonal += matriks[i][j];
            }
        }
        std::cout << std::endl;
    }

    std::cout << "\nJumlah Diagonal Utama (1+5+9): " << sumDiagonal << std::endl;

    return 0;
}