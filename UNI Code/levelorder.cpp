#include <iostream>
#include <queue> // Include the queue library for using std::queue
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

// Function for level-order traversal using std::queue
void levelorder(TreeNode* treeNode) {
    if (treeNode == nullptr) return;

    queue<TreeNode*> q; // Create a queue of TreeNode pointers
    q.push(treeNode);   // Enqueue the root node

    while (!q.empty()) {
        treeNode = q.front(); // Get the node at the front of the queue
        q.pop();              // Remove the node from the queue

        cout << *(treeNode->getInfo()) << " "; // Print the node's info

        // Enqueue the left child if it exists
        if (treeNode->getLeft() != nullptr) {
            q.push(treeNode->getLeft());
        }

        // Enqueue the right child if it exists
        if (treeNode->getRight() != nullptr) {
            q.push(treeNode->getRight());
        }
    }

    cout << endl; // Print a newline at the end of the traversal
}

// Main function to demonstrate level-order traversal
int main() {
    // Create a simple binary tree
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(18);

    // Perform level-order traversal
    cout << "Level-order traversal: ";
    levelorder(root);

    return 0;
}
