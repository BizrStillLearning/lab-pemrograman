#include <iostream>
#include <cstring>

int main() {
    char str1[20] = "Halo";
    char str2[] = " Dunia";
    char bufferKecil[5];

    std::cout << "Panjang str1: " << strlen(str1) << std::endl;

    if (strcmp(str1, "Halo") == 0) {
        std::cout << "str1 identik dengan 'Halo'" << std::endl;
    }

    strcat(str1, str2);
    std::cout << "Hasil strcat (str1 + str2): " << str1 << std::endl;

    std::cout << "\nMencoba strcpy ke buffer yang terlalu kecil..." << std::endl;
    strcpy(bufferKecil, str1);
    
    std::cout << "Isi bufferKecil: " << bufferKecil << std::endl;

    return 0;
}