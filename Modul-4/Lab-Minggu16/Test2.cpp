#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

Node* buatNode(char data) {
    Node* baru = new Node;
    baru->data = data;
    baru->left = NULL;
    baru->right = NULL;
    return baru;
}

int main() {
    Node* A = buatNode('A');
    Node* B = buatNode('B');
    Node* C = buatNode('C');
    Node* D = buatNode('D');
    Node* E = buatNode('E');

    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;

    cout << "Root      : " << A->data << endl;
    cout << "Kiri Root : " << A->left->data << endl;
    cout << "Kanan Root: " << A->right->data << endl;
    cout << "Kiri B    : " << B->left->data << endl;
    cout << "Kanan B   : " << B->right->data << endl;

    return 0;
}