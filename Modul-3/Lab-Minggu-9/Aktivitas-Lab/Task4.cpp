#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    std::string name;
    double gpa;
};

int main() {
    std::vector<Student> students = { {"Alice", 3.5}, {"Bob", 3.9}, {"Charlie", 3.5} };

    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.gpa == b.gpa;
    });
    
    std::stable_sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.gpa > b.gpa;
    });
    return 0;
}