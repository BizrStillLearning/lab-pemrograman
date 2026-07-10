#include <iostream>

using namespace std;

struct TreeLift {
    char data;
    TreeLift* right;
    TreeLift* left;
};

TreeLift* CreateNode (char data){
    TreeLift* node = new TreeLift;
    node->data = data;
    node->right = NULL;
    return node;
}

int main() {
    TreeLift* A = CreateNode('a');
    TreeLift* B = CreateNode('b');
    TreeLift* C = CreateNode('c');
    TreeLift* D = CreateNode('d');
    TreeLift* E = CreateNode('e');

    A->left = B;
    B->right = C;
    C->right = D;
    D->left = E;

    cout << "Root = " << A->data << endl;
    cout << "Kiri Root = " << A->left->data << endl;
    cout << "Kanan Root " << A->left->data << endl;
    cout << "Kiri B " << B->left->data << endl;
    cout << "Kanan B " << B->right->data << endl;

    return 0;
}

