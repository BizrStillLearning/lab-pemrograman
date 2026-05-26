#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    std::string name;
    double ipk;
};

void printStudents(const std::vector<Student>& students) {
    for (const auto& s : students) {
        std::cout << s.name << " - " << s.ipk << std::endl;
    }
}

int main() {
    std::vector<Student> students = {
        {"Abidzar", 3.5},
        {"Albany", 3.5},
        {"Kaizer", 3.9},
        {"Fathul", 3.5}
    };

    std::vector<Student> sortStudents = students;

    std::sort(sortStudents.begin(), sortStudents.end(),
        [](const Student& a, const Student& b) {
            return a.ipk > b.ipk;
        });

    std::cout << "Hasil std::sort:\n";
    printStudents(sortStudents);

    std::vector<Student> stableStudents = students;

    std::stable_sort(stableStudents.begin(), stableStudents.end(),
        [](const Student& a, const Student& b) {
            return a.ipk > b.ipk;
        });

    std::cout << "Hasil std::stable_sort:\n";
    printStudents(stableStudents);

    return 0;
}