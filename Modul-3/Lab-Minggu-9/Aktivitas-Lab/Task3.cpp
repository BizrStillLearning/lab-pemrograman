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
        {"Abidzar", 3.4}, {"Albany", 3.9}, {"Kaizer", 3.4}, {"David", 3.7}
    };

    std::sort(classRoster.begin(), classRoster.end(), [](const Student& a, const Student& b) {
        return a.gpa > b.gpa; 
    });

    std::cout << "--- Roster Berdasarkan IPK Tertinggi ---\n";
    for (const auto& s : classRoster) {
        std::cout << s.name << " : " << s.gpa << "\n";
    }
    return 0;
}