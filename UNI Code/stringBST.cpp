#include <iostream>
#include <cstring> // For strcmp
using namespace std;

// TreeNode class definition for strings
class TreeNode {
public:
    char* info;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(char* value) {
        info = new char[strlen(value) + 1];
        strcpy(info, value);
        left = nullptr;
        right = nullptr;
    }

    ~TreeNode() {
        delete[] info;
    }

    // Getters
    char* getInfo() {
        return info;
    }

    TreeNode* getLeft() {
        return left;
    }

    TreeNode* getRight() {
        return right;
    }

    // Setters
    void setLeft(TreeNode* node) {
        left = node;
    }

    void setRight(TreeNode* node) {
        right = node;
    }
};

// Function to insert a string into the BST
void insert(TreeNode* root, char* info) {
    TreeNode* node = new TreeNode(info);
    TreeNode* p = root;
    TreeNode* q = root;

    while (strcmp(info, p->getInfo()) != 0 && q != nullptr) {
        p = q;
        if (strcmp(info, p->getInfo()) < 0) {
            q = p->getLeft();
        } else {
            q = p->getRight();
        }
    }

    if (strcmp(info, p->getInfo()) == 0) {
        cout << "Attempt to insert duplicate: " << info << endl;
        delete node;
    } else if (strcmp(info, p->getInfo()) < 0) {
        p->setLeft(node);
    } else {
        p->setRight(node);
    }
}

// Function for inorder traversal
void inorder(TreeNode* treeNode) {
    if (treeNode != nullptr) {
        inorder(treeNode->getLeft());
        cout << treeNode->getInfo() << " ";
        inorder(treeNode->getRight());
    }
}

// Function to create the word tree and print strings in order
void wordTree() {
    // Array of words to insert into the tree
    char* words[] = {
        "babble", "fable", "jacket", "backup", "eagle", "daily", "gain",
        "bandit", "abandon", "abash", "accuse", "economy", "adhere",
        "advise", "cease", "debunk", "feeder", "genius", "fetch", "chain", nullptr
    };

    // Create the root node
    TreeNode* root = new TreeNode(words[0]);

    // Insert words into the tree
    for (int i = 1; words[i] != nullptr; i++) {
        insert(root, words[i]);
    }

    // Print words in-order
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    // Clean up memory
    delete root;
}

int main() {
    wordTree();
    return 0;
    

}
