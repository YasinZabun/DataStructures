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
            else {
                insert(root->left,item);
            }
        }
    }
}

void preorderFBT(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
    }
    if (root->left != NULL)
    {
        preorderFBT(root->left);
        preorderFBT(root->right);
    }
}

int main()
{
    int items[] = {85, 51, 80, 79, 18, 32, 89, 74, 12};
    Node *bTRoot = new Node(85);
    insert(bTRoot, 51);
    insert(bTRoot, 80);
    insert(bTRoot, 79);
    insert(bTRoot, 18);
    insert(bTRoot, 32);
    insert(bTRoot, 89);
    insert(bTRoot, 74);
    insert(bTRoot, 12);
    preorderFBT(bTRoot);

    //             85
    //         51          80
    //     79      18    32    89
    // 74      12
    return 0;
}
