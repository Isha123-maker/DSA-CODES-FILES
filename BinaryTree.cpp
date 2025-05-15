#include <iostream>
#include <vector>

using namespace std;

// Class for crating a node of Binary Tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function for building Tree in Pre-Order sequence
int static idx = -1;
Node *preOrder(vector<int> preOrderSequqnce)
{
    idx++;

    if (preOrderSequqnce[idx] == -1)
    {
        return NULL;
    }

    Node *root = new Node(preOrderSequqnce[idx]);
    root->left = preOrder(preOrderSequqnce);  // Left Subtree
    root->right = preOrder(preOrderSequqnce); // Right Subtree

    return root;
}

// Function For Pre-Order Traversal
void preOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Function For InOrder Traversal
void inOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left);

    cout << root->data << " ";

    inOrderTraversal(root->right);
}

// Function For Post-Order Traversal
void postOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main()
{
    vector<int> preOrderSequqnce = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = preOrder(preOrderSequqnce);
    postOrderTraversal(root);
    // cout << root->data <<endl;
    // cout << root->left->data <<endl;
    // cout << root->right->data <<endl;
    return 0;
}