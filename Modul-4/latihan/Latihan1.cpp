// Latihan 1: Struct, Custom Sorting, dan Binary Search (Modul 3)
// Kombinasi antara sorting dan binary search mencakup sekitar 40% dari tipe soal ujian CPE
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Mendefinisikan tipe data kustom (Structs & OOP) [3]
struct Student {
    int id;
    string name;
    double gpa;
};

// Fungsi Binary Search iteratif kustom [4, 5]
int binarySearchById(const vector<Student>& arr, int targetId) {
    int lo = 0, hi = (int)arr.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2; // Mencegah integer overflow [5]
        if (arr[mid].id == targetId) return mid;
        else if (arr[mid].id < targetId) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1; // Tidak ditemukan
}

int main() {
    vector<Student> roster = {
        {103, "Carol", 3.90},
        {101, "Alice", 3.75},
        {102, "Bob", 3.50}
    };

    // Task: Mengurutkan struct berdasarkan ID secara menaik (Ascending) [6, 7]
    sort(roster.begin(), roster.end(), [](const Student& a, const Student& b) {
        return a.id < b.id;
    });

    // Task: Mencari siswa dengan ID tertentu menggunakan Binary Search
    int target = 102;
    int index = binarySearchById(roster, target);

    if (index != -1) {
        cout << "Ditemukan: " << roster[index].name << " dengan IPK " << roster[index].gpa << "\n";
    }

    return 0;
}

