#include <iostream>

// Template class for TreeNode
template <class Object>
class TreeNode {
public:
    // Constructors
    TreeNode() : object(nullptr), left(nullptr), right(nullptr) {}

    TreeNode(Object* object) : object(object), left(nullptr), right(nullptr) {}

    // Getters and Setters for the node's information
    Object* getInfo() const {
        return object;
    }

    void setInfo(Object* object) {
        this->object = object;
    }

    // Getters and Setters for the left child
    TreeNode* getLeft() const {
        return left;
    }

    void setLeft(TreeNode* left) {
        this->left = left;
    }

    // Getters and Setters for the right child
    TreeNode* getRight() const {
        return right;
    }

    void setRight(TreeNode* right) {
        this->right = right;
    }

    // Checks if the node is a leaf (i.e., has no children)
    bool isLeaf() const {
        return left == nullptr && right == nullptr;
    }

private:
    Object* object;
    TreeNode* left;
    TreeNode* right;
};

// Main function for testing TreeNode
int main() {
    // Creating TreeNode objects with integer pointers
    int val1 = 10, val2 = 20, val3 = 30;
    TreeNode<int> node1(&val1);
    TreeNode<int> node2(&val2);
    TreeNode<int> node3(&val3);

    // Set left and right children
    node1.setLeft(&node2);
    node1.setRight(&node3);

    // Display node info and check if nodes are leaves
    std::cout << "Node1 info: " << *(node1.getInfo()) << std::endl;
    std::cout << "Node1 is a leaf: " << node1.isLeaf() << std::endl;

    std::cout << "Node2 info: " << *(node2.getInfo()) << std::endl;
    std::cout << "Node2 is a leaf: " << node2.isLeaf() << std::endl;

    std::cout << "Node3 info: " << *(node3.getInfo()) << std::endl;
    std::cout << "Node3 is a leaf: " << node3.isLeaf() << std::endl;

    return 0;
}
