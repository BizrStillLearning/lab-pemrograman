#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int x) {
    if (!root) return new TreeNode(x);
    if (x < root->data) root->left = insert(root->left, x);
    else if (x > root->data) root->right = insert(root->right, x);
    return root;
}

TreeNode* findMin(TreeNode* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        TreeNode* temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inOrder(TreeNode* root) {
    if (!root) return;
    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    TreeNode* root = nullptr;
    int values[] = {50, 30, 70, 20, 40, 60, 80};

    for (int v : values) root = insert(root, v);

    std::cout << "BST Awal (In-Order): ";
    inOrder(root);
    std::cout << "\n\n";

    std::cout << "Menghapus 20 (Kasus 1: Leaf Node)...\n";
    root = deleteNode(root, 20);
    std::cout << "Hasil: "; inOrder(root); std::cout << "\n\n";

    std::cout << "Menghapus 40 (Agar 30 hanya punya 1 anak kiri)...\n";
    root = deleteNode(root, 40);

    std::cout << "Menghapus 30 (Kasus 2: Satu Anak)...\n";
    root = deleteNode(root, 30);
    std::cout << "Hasil: "; inOrder(root); std::cout << "\n\n";

    std::cout << "Menghapus 50 (Kasus 3: Dua Anak - Root Utama)...\n";
    root = deleteNode(root, 50);
    std::cout << "Hasil: "; inOrder(root); std::cout << "\n";
    std::cout << "(Nilai 50 digantikan oleh 60 sebagai in-order successor-nya)\n";

    return 0;
}

