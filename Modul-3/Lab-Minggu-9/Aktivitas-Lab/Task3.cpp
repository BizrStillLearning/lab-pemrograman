#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    std::string name;
    double gpa;
};

int main() {
    std::vector<Student> classRoster = {
        {"Alice", 3.4}, {"Bob", 3.9}, {"Charlie", 3.4}, {"David", 3.7}
    };

    std::sort(classRoster.begin(), classRoster.end(), [](const Student& a, const Student& b) {
        return a.gpa > b.gpa; 
    });

    std::cout << "--- Roster Berdasarkan GPA Tertinggi ---\n";
    for (const auto& s : classRoster) {
        std::cout << s.name << " : " << s.gpa << "\n";
    }
    return 0;
}