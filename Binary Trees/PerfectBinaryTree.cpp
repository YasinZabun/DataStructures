#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int value)
    {
        data = value;
        right = NULL;
        left = NULL;
    }
};
void insert(Node *root, int item)
{
    if (root->left == NULL)
    {
        Node *newNode = new Node(item);
        root->left = newNode;
    }
    else if (root->right == NULL)
    {
        Node *newNode = new Node(item);
        root->right = newNode;
    }
    else
    {
        if (root->left->left == NULL || root->left->right == NULL)
        {
            insert(root->left, item);
        }
        else
        {
            if (root->right->left == NULL || root->right->right == NULL)
            {
                insert(root->right, item);
            }
            else
            {
                insert(root->left, item);
            }
        }
    }
}
bool isPerfectBinaryTree(Node *root)
{
    if (root->left != NULL && root->right != NULL)
    {
        return isPerfectBinaryTree(root->left) && isPerfectBinaryTree(root->right);
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    return false;
}
void preorderPBT(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
    }
    if (root->left != NULL)
    {
        preorderPBT(root->left);
    }
    if (root->right != NULL)
    {
        preorderPBT(root->right);
    }
}

int main()
{
    Node *bTRoot = new Node(1);
    insert(bTRoot, 2);
    insert(bTRoot, 3);
    insert(bTRoot, 4);
    insert(bTRoot, 5);
    insert(bTRoot, 6);
    insert(bTRoot, 7);
    insert(bTRoot, 8);
    preorderPBT(bTRoot);
    if (isPerfectBinaryTree(bTRoot))
    {
        cout << "This tree is perfect tree";
    }
    else
    {
        cout << "This tree is not perfect tree";
    }

    //               1
    //         2          3
    //     4      5    6     7
    // 8
    return 0;
}
