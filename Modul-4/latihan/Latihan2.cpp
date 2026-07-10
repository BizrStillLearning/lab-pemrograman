// Latihan 2: Implementasi Stack untuk Evaluasi Kurung (Modul 4)
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Fungsi untuk mengecek keseimbangan kurung menggunakan LIFO Stack [8-10]
bool isBalanced(const string& expr) {
    stack<char> s;
    for (char c : expr) {
        // Jika kurung buka, masukkan ke stack (Push)
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        }
        // Jika kurung tutup, periksa kecocokannya dengan elemen teratas stack (Pop)
        else if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) return false;
            char open = s.top();
            s.pop();

            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                return false;
                }
        }
    }
    return s.empty(); // Stack harus kosong di akhir jika seimbang [10]
}

int main() {
    cout << "Test 1 ({[]}): " << (isBalanced("({[]})") ? "Seimbang" : "Tidak Seimbang") << "\n";
    cout << "Test 2 ({[}): " << (isBalanced("({[})") ? "Seimbang" : "Tidak Seimbang") << "\n";
    return 0;
}