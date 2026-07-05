#include <iostream>
#include <algorithm>

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

void preOrder(TreeNode* root) {
    if (!root) return;
    std::cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode* root) {
    if (!root) return;
    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(TreeNode* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->data << " ";
}

int height(TreeNode* root) {
    if (!root) return -1;
    return 1 + std::max(height(root->left), height(root->right));
}

int countNodes(TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    TreeNode* root = nullptr;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    
    std::cout << "Memasukkan data ke BST: 50, 30, 70, 20, 40, 60, 80\n";
    for (int v : values) {
        root = insert(root, v);
    }

    std::cout << "\n--- Task 2: Traversals ---\n";
    std::cout << "Pre-order  (Root-L-R): "; preOrder(root); std::cout << "\n";
    std::cout << "In-order   (L-Root-R): "; inOrder(root); std::cout << " (Terurut!)\n";
    std::cout << "Post-order (L-R-Root): "; postOrder(root); std::cout << "\n";

    std::cout << "\n--- Task 3: Height & Node Count ---\n";
    std::cout << "Tinggi (Height) pohon : " << height(root) << "\n";
    std::cout << "Total Node di pohon   : " << countNodes(root) << "\n";

    std::cout << "\n--- Task 4: Degenerate BST Test ---\n";
    TreeNode* degenRoot = nullptr;
    int degenValues[] = {1, 2, 3, 4, 5};
    
    for (int v : degenValues) {
        degenRoot = insert(degenRoot, v);
    }
    
    std::cout << "Tinggi Degenerate BST (1, 2, 3, 4, 5): " << height(degenRoot) << "\n";
    std::cout << "Penjelasan: Karena dimasukkan secara terurut, BST berubah bentuk menjadi seperti Linked List lurus ke kanan.\n";

    return 0;
}