#include <iostream>
#include <climits>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

bool isBSTUtil(TreeNode* root, long minVal, long maxVal) {
    if (!root) return true;

    if (root->data <= minVal || root->data >= maxVal) {
        return false;
    }

    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(TreeNode* root) {
    return isBSTUtil(root, LONG_MIN, LONG_MAX);
}

int main() {
    TreeNode* validTree = new TreeNode(10);
    validTree->left = new TreeNode(5);
    validTree->right = new TreeNode(15);
    validTree->left->left = new TreeNode(2);
    validTree->left->right = new TreeNode(7);

    TreeNode* invalidTree = new TreeNode(10);
    invalidTree->left = new TreeNode(5);
    invalidTree->right = new TreeNode(15);
    invalidTree->right->left = new TreeNode(8);

    std::cout << "--- Uji Validitas BST ---\n";
    std::cout << "Pohon 1 (Valid)  : " << (isBST(validTree) ? "Ya, ini BST" : "Bukan BST") << "\n";
    std::cout << "Pohon 2 (Invalid): " << (isBST(invalidTree) ? "Ya, ini BST" : "Bukan BST") << "\n";

    return 0;
}