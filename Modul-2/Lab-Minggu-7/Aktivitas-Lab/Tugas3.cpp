#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

bool isPalindrome(std::string str) {
    std::string temp = str;
    std::reverse(temp.begin(), temp.end());
    return str == temp;
}

int main() {
    std::vector<std::string> kataUji = {"KATAK", "RADAR", "MAKAN", "MALAM", "LEVEL"};

    std::cout << "--- Pengujian Palindrom ---" << std::endl;
    for (const std::string& kata : kataUji) {
        std::cout << "Kata: " << kata << " -> " 
                  << (isPalindrome(kata) ? "PALINDROM" : "BUKAN PALINDROM") 
                  << std::endl;
    }

    return 0;
}