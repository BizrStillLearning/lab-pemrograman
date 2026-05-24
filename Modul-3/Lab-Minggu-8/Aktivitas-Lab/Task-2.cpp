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
    Student bob = {"Bob", 102, 3.2};
    
    std::cout << "GPA Bob awal : " << bob.gpa << std::endl;
    
    updateGPA(bob, 3.6);
    
    std::cout << "GPA Bob baru : " << bob.gpa << " (Terbukti Berubah!)" << std::endl;
    
    return 0;
}