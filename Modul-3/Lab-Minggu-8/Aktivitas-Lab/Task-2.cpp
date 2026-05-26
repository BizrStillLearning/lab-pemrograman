#include <iostream>
#include <string>

struct Student {
    std::string name;
    int id;
    double gpa;
};

void updateGPA(Student& s, double newGpa) {
    s.gpa = newGpa;
}

int main() {
    Student bob = {"Abidzar", 01, 3.5};
    
    std::cout << "IPK Abidzar awal : " << bob.gpa << std::endl;
    
    updateGPA(bob, 3.8);
    
    std::cout << "IPK Abidzar baru : " << bob.gpa << "(Berubah)" << std::endl;
    
    return 0;
}