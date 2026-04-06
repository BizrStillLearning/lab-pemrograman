#include <iostream>
#include <string>

std::string caesarCipher(std::string text, int k) {
    std::string result = "";

    k = k % 26;

    for (char c : text) {
        if (isupper(c)) {
            result += char(int('A' + (c - 'A' + k) % 26));
        } else if (islower(c)) {
            result += char(int('a' + (c - 'a' + k) % 26));
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    std::string pesan = "Halo Dunia, C++ 2026!";
    int kunci = 3;

    std::string enkripsi = caesarCipher(pesan, kunci);

    std::cout << "Pesan Asli : " << pesan << std::endl;
    std::cout << "Kunci      : " << kunci << std::endl;
    std::cout << "Enkripsi   : " << enkripsi << std::endl;

    return 0;
}