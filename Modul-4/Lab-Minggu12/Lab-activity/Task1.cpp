#include <iostream>

class IntStack {
private:
    int data[1000];
    int topIdx;

public:
    IntStack() {
        topIdx = -1;
    }

    void push(int x) {
        if (topIdx >= 999) {
            std::cout << "Stack overflow!\n";
            return;
        }
        data[++topIdx] = x;
    }

    int pop() {
        if (topIdx < 0) {
            std::cout << "Stack underflow!\n";
            return -1;
        }
        return data[topIdx--];
    }

    int top() const {
        if (topIdx < 0) return -1;
        return data[topIdx];
    }

    bool empty() const {
        return topIdx < 0;
    }
};

int main() {
    IntStack s;

    std::cout << "--- Pengujian IntStack ---\n";
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Nilai teratas (Top): " << s.top() << "\n";

    std::cout << "Isi stack saat di-pop: ";
    while (!s.empty()) {
        std::cout << s.pop() << " ";
    }
    std::cout << "\n";

    return 0;
}