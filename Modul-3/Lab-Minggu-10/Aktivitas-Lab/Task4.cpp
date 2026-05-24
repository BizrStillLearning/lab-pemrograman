#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    int id;
    std::string name;
};

int main() {
    std::vector<Student> roster = {
        {105, "Eva"}, {101, "Alice"}, {103, "Charlie"}, {102, "Bob"}
    };

    std::sort(roster.begin(), roster.end(), [](const Student& a, const Student& b) {
        return a.id < b.id;
    });

    int targetId = 103;

    auto it = std::lower_bound(roster.begin(), roster.end(), Student{targetId, ""},
        [](const Student& a, const Student& b) {
            return a.id < b.id;
        });

    std::cout << "--- Pencarian Siswa ---\n";
    if (it != roster.end() && it->id == targetId) {
        std::cout << "Siswa Ditemukan! ID: " << it->id << ", Nama: " << it->name << "\n";
    } else {
        std::cout << "Siswa dengan ID " << targetId << " tidak ditemukan.\n";
    }

    return 0;
}