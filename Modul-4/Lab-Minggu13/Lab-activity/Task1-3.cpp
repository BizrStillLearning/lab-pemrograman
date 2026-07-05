#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    void pushFront(int x) {
        Node* n = new Node(x);
        n->next = head;
        head = n;
    }
    
    void pushBack(int x) {
        Node* n = new Node(x);
        if (!head) { 
            head = n; 
            return; 
        }
        Node* cur = head;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = n;
    }

    void print() {
        for (Node* cur = head; cur; cur = cur->next) {
            std::cout << cur->data << " -> ";
        }
        std::cout << "NULL\n";
    }

    bool contains(int target) {
        for (Node* cur = head; cur; cur = cur->next) {
            if (cur->data == target) return true;
        }
        return false;
    }

    void reverse() {
        Node *prev = nullptr, *cur = head, *next = nullptr;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }
};

int main() {
    LinkedList list;
    
    std::cout << "--- Task 1: Insert & Print ---\n";
    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);
    list.pushFront(5);
    std::cout << "List awal: ";
    list.print();

    std::cout << "\n--- Task 2: Search ---\n";
    std::cout << "Cari 20: " << (list.contains(20) ? "Ditemukan" : "Tidak ditemukan") << "\n";
    std::cout << "Cari 99: " << (list.contains(99) ? "Ditemukan" : "Tidak ditemukan") << "\n";

    std::cout << "\n--- Task 3: Reverse ---\n";
    list.reverse();
    std::cout << "List setelah reverse: ";
    list.print();

    return 0;
}