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
    if (item < root->data)
    {
        if (root->left == NULL)
        {
            root->left = new Node(item);
        }
        else
        {
            insert(root->left, item);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = new Node(item);
        }
        else
        {
            insert(root->right, item);
        }
    }
}

void preorderBST(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        if (root->left != NULL)
        {
            preorderBST(root->left);
            preorderBST(root->right);
        }
    }
}
Node *search(Node *root, int item)
{
    if (root != NULL)
    {
        if (root->data == item)
            return root;
        else
        {
            if (root->data > item)
                search(root->left, item);
            else
                search(root->right, item);
        }
    }
}
int main()
{
    Node *bTRoot = new Node(52);
    insert(bTRoot, 51);
    insert(bTRoot, 80);
    insert(bTRoot, 79);
    insert(bTRoot, 18);
    insert(bTRoot, 32);
    insert(bTRoot, 89);
    insert(bTRoot, 74);
    insert(bTRoot, 12);
    preorderBST(bTRoot);
    cout << endl
         << search(bTRoot, 18)->data;

    //               52
    //         51          80
    //     18         79      89
    //  12    32  74
    return 0;
}
