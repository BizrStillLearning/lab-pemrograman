#include <iostream>

class IntQueue {
private:
    static const int CAP = 5;
    int data[CAP];
    int frontIdx;
    int backIdx;
    int count;

public:
    IntQueue() : frontIdx(0), backIdx(0), count(0) {}

    void enqueue(int x) {
        if (count == CAP) {
            std::cout << "Queue full! Tidak bisa memasukkan " << x << "\n";
            return;
        }
        data[backIdx] = x;
        backIdx = (backIdx + 1) % CAP;
        count++;
    }

    int dequeue() {
        if (count == 0) {
            std::cout << "Queue empty!\n";
            return -1;
        }
        int x = data[frontIdx];
        frontIdx = (frontIdx + 1) % CAP;
        count--;
        return x;
    }

    bool empty() const {
        return count == 0;
    }
};

int main() {
    IntQueue q;

    std::cout << "--- Pengujian Circular Queue ---\n";
    std::cout << "Memasukkan 5 elemen...\n";
    q.enqueue(10); q.enqueue(20); q.enqueue(30); q.enqueue(40); q.enqueue(50);

    q.enqueue(60);

    std::cout << "Mengeluarkan 2 elemen: " << q.dequeue() << " dan " << q.dequeue() << "\n";

    std::cout << "Memasukkan 2 elemen baru (memicu wrap-around ke indeks awal)...\n";
    q.enqueue(60); q.enqueue(70);

    std::cout << "Menguras seluruh isi Queue: ";
    while (!q.empty()) {
        std::cout << q.dequeue() << " ";
    }
    std::cout << "\n";

    return 0;
}