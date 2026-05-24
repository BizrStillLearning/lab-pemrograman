#include <iostream>

class Counter {
private:
    int value;

public:
    Counter() {
        value = 0; 
    } 

    void increment() { 
        value++; 
    }
    
    void decrement() {
        if (value > 0) {
            value--;
        }
    }
    
    int getValue() { 
        return value; 
    }
};

int main() {
    Counter c;
    
    c.increment();
    c.increment();
    std::cout << "Nilai setelah 2x increment: " << c.getValue() << std::endl;
    
    c.decrement();
    std::cout << "Nilai setelah 1x decrement: " << c.getValue() << std::endl;
    
    c.decrement();
    c.decrement();
    std::cout << "Nilai setelah dipaksa minus  : " << c.getValue() << " (Tetap 0, aman!)" << std::endl;

    return 0;
}