#include <iostream>
#include <stack>

class QueueViaStacks {
private:
    std::stack<int> s1;
    std::stack<int> s2;

public:
    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        if (s2.empty()) {
            std::cout << "Queue empty!\n";
            return -1;
        }

        int val = s2.top();
        s2.pop();
        return val;
    }
};

int main() {
    QueueViaStacks q;

    std::cout << "--- Pengujian Queue via 2 Stacks ---\n";

    std::cout << "Enqueue: 10, 20, 30\n";
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Dequeue: " << q.dequeue() << "\n";

    std::cout << "Enqueue: 40, 50\n";
    q.enqueue(40);
    q.enqueue(50);

    std::cout << "Dequeue 4x:\n";
    std::cout << q.dequeue() << "\n";
    std::cout << q.dequeue() << "\n";
    std::cout << q.dequeue() << "\n";
    std::cout << q.dequeue() << "\n";

    return 0;
}