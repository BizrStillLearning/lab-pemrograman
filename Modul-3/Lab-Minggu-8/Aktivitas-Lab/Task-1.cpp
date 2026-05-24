#include <iostream>
#include <string>

struct Student {
    std::string name;
    int id;
    double gpa;
};

int main() {
    Student roster[5] = {
        {"Alice", 101, 3.5},
        {"Bob", 102, 3.2},
        {"Charlie", 103, 3.9},
        {"David", 104, 2.8},
        {"Eva", 105, 3.7}
    };

    std::cout << "--- Student Roster ---" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "Nama: " << roster[i].name
                  << " | ID: " << roster[i].id
                  << " | GPA: " << roster[i].gpa << std::endl;
    }
    return 0;
}