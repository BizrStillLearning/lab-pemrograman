#include <iostream>

void fungsiKedua(int b) {
    int variabelLokal2 = b;
    std::cout << "Fungsi Kedua - Alamat variabelLokal2 : " << &variabelLokal2 << std::endl;
}

void fungsiPertama(int a) {
    int variabelLokal1 = a;
    std::cout << "Fungsi Pertama - Alamat variabelLokal1: " << &variabelLokal1 << std::endl;
    fungsiKedua(variabelLokal1); // Panggilan bersarang
}

int main() {
    int variabelMain = 10;
    std::cout << "Main           - Alamat variabelMain   : " << &variabelMain << std::endl;
    fungsiPertama(variabelMain);
    return 0;
}
