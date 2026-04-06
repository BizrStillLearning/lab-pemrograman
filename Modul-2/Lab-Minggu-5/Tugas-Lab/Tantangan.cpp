#include <iostream>

struct DynamicStack {
    int* data;
    int capacity;
    int top;

    DynamicStack(int cap) {
        capacity = cap;
        data = new int[capacity];
        top = -1;
    }

    void push(int value) {
        if (top + 1 == capacity) {
            int newCap = capacity * 2;
            int* newData = new int[newCap];
            for (int i = 0; i <= top; i++) newData[i] = data[i];
            
            delete[] data;
            data = newData;
            capacity = newCap;
            std::cout << "(Kapasitas bertambah menjadi: " << capacity << ")" << std::endl;
        }
        data[++top] = value;
    }

    int pop() {
        if (top == -1) return -1;
        return data[top--];
    }

    ~DynamicStack() { delete[] data; }
};

int main() {
    DynamicStack s(2);
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Pop: " << s.pop() << std::endl;
    std::cout << "Pop: " << s.pop() << std::endl;

    return 0;
}