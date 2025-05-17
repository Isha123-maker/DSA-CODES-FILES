#include <iostream>
#include <vector>
#include <queue>

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

// Function for Level Order Traversal
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (q.size() > 0)
    {
        Node *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            if (!q.empty())
            {
                cout << endl;
                q.push(NULL);
                continue;
            }
            else
            {
                break;
            }
        }

        cout << curr->data << " ";

        if (curr->left != NULL)
        {
            q.push(curr->left);
        }

        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
}

// Function for finding the height of a tree
int heightOfTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);

    return max(leftHeight, rightHeight) + 1;
}

// Function for Count of Nodes
int countOfNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftSTCount = countOfNodes(root->left);
    int rightSTCount = countOfNodes(root->right);

    return leftSTCount + rightSTCount + 1;
}

// Function for Sum of Nodes
int sumOfNodes(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);

    return leftSum + rightSum + root->data;
}

int main()
{
    vector<int> preOrderSequqnce = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = preOrder(preOrderSequqnce);
    cout << "Sum of Nodes of a tree are:" << sumOfNodes(root);
    // levelOrderTraversal(root);
    // cout << root->data <<endl;
    // cout << root->left->data <<endl;
    // cout << root->right->data <<endl;
    return 0;
}