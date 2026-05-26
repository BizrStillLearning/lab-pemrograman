#include <iostream>
#include <string>

struct Student {
    std::string name;
    int id;
    double gpa;
};

int main() {
    Student roster[5] = {
        {"Abidzar", 01, 3.5},
        {"Budi", 02, 3.2},
        {"Kaizer", 03, 3.9},
        {"Albany", 04, 2.8},
        {"Fathul", 05, 3.7}
    };

    std::cout << "--- Student Roster ---" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "Nama: " << roster[i].name
                  << " | ID: " << roster[i].id
                  << " | IPK: " << roster[i].gpa << std::endl;
    }
    return 0;
}