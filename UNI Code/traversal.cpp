#include <iostream>
using namespace std;

// TreeNode class definition
class TreeNode {
public:
    int info;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int value) : info(value), left(nullptr), right(nullptr) {}

    // Getters for information and child nodes
    int* getInfo() {
        return &info;
    }

    TreeNode* getLeft() {
        return left;
    }

    TreeNode* getRight() {
        return right;
    }
};

// BinaryTree class definition
class BinaryTree {
public:
    TreeNode* root;

    // Constructor
    BinaryTree() : root(nullptr) {}

    // Function to insert nodes
    void insert(int value) {
        if (root == nullptr) {
            root = new TreeNode(value);
        } else {
            insertHelper(root, value);
        }
    }

    // Preorder traversal
    void preorder(TreeNode* treeNode) {
        if (treeNode != nullptr) {
            cout << *(treeNode->getInfo()) << " ";
            preorder(treeNode->getLeft());
            preorder(treeNode->getRight());
        }
    }

    // Inorder traversal
    void inorder(TreeNode* treeNode) {
        if (treeNode != nullptr) {
            inorder(treeNode->getLeft());
            cout << *(treeNode->getInfo()) << " ";
            inorder(treeNode->getRight());
        }
    }

    // Postorder traversal
    void postorder(TreeNode* treeNode) {
        if (treeNode != nullptr) {
            postorder(treeNode->getLeft());
            postorder(treeNode->getRight());
            cout << *(treeNode->getInfo()) << " ";
        }
    }

private:
    void insertHelper(TreeNode* node, int value) {
        if (value < node->info) {
            if (node->left == nullptr) {
                node->left = new TreeNode(value);
            } else {
                insertHelper(node->left, value);
            }
        } else {
            if (node->right == nullptr) {
                node->right = new TreeNode(value);
            } else {
                insertHelper(node->right, value);
            }
        }
    }
};

int main() {
    // Create a binary tree and insert nodes
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    // Display traversals
    cout << "Preorder: ";
    tree.preorder(tree.root);
    cout << endl;

    cout << "Inorder: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Postorder: ";
    tree.postorder(tree.root);
    cout << endl;

    return 0;
}
