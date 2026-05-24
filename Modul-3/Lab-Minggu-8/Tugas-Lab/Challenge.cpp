#include <iostream>

class Fraction {
private:
    int num;
    int den;

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce() {
        int common = gcd(num, den);
        num /= common;
        den /= common;
    }

public:
    Fraction(int n, int d) {
        num = n;
        den = d;
        reduce();
    }

    Fraction add(Fraction other) {
        int newNum = (num * other.den) + (other.num * den);
        int newDen = den * other.den;
        return Fraction(newNum, newDen);
    }

    Fraction multiply(Fraction other) {
        int newNum = num * other.num;
        int newDen = den * other.den;
        return Fraction(newNum, newDen);
    }

    void print() {
        std::cout << num << "/" << den << std::endl;
    }
};

int main() {
    Fraction f1(1, 2);
    Fraction f2(2, 3);

    std::cout << "Fraction 1: "; f1.print();
    std::cout << "Fraction 2: "; f2.print();

    Fraction resultAdd = f1.add(f2);
    std::cout << "Hasil Tambah (1/2 + 2/3): "; resultAdd.print();

    Fraction resultMul = f1.multiply(f2);
    std::cout << "Hasil Kali   (1/2 * 2/3): "; resultMul.print();

    return 0;
}