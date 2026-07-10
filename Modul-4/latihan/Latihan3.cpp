// Latihan 3: Binary Search Tree (BST) Node Insertion & Traversal (Modul 4)
#include <iostream>

using namespace std;

// Struktur untuk Node Tree [13]
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

// Fungsi penyisipan rekursif ke dalam BS T [13]
TreeNode* insert(TreeNode* root, int x) {
    if (!root) return new TreeNode(x);

    if (x < root->data)
        root->left = insert(root->left, x); // Aturan BST: kiri lebih kecil [14]
    else if (x > root->data)
        root->right = insert(root->right, x); // Aturan BST: kanan lebih besar [14]

    return root;
}

// Fungsi In-Order Traversal (Kiri - Root - Kanan) [12, 15]
void inOrder(TreeNode* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->data << " "; // Data akan tercetak secara terurut [11]
    inOrder(root->right);
}

int main() {
    TreeNode* root = nullptr;
    // Menyisipkan nilai ke BST
    for (int v : {8, 3, 10, 1, 6, 14, 13}) {
        root = insert(root, v);
    }

    cout << "Hasil In-Order Traversal: ";
    inOrder(root); // Output yang diharapkan: 1 3 6 8 10 13 14 [11]
    cout << "\n";

    return 0;
}