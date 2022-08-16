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

void preorderBHT(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
    }
    if (root->left != NULL)
    {
        preorderBHT(root->left);
        preorderBHT(root->right);
    }
}

Node *bTRoot = new Node(85);

void maxHeapify(Node *root)
{
    if (root != NULL)
    {
        if (root->left != NULL)
        {
            if (root->left->data > root->data)
            {
                int temp = root->data;
                root->data = root->left->data;
                root->left->data = temp;
                maxHeapify(bTRoot);
            }
            else
            {
                maxHeapify(root->left);
            }
        }
        if (root->right != NULL)
        {
            if (root->right->data > root->data)
            {

                int temp = root->data;
                root->data = root->right->data;
                root->right->data = temp;
                maxHeapify(bTRoot);
            }
            else
            {
                maxHeapify(root->right);
            }
        }
    }
}

void minHeapify(Node *root)
{
    if (root != NULL)
    {
        if (root->left != NULL)
        {
            if (root->left->data < root->data)
            {
                int temp = root->data;
                root->data = root->left->data;
                root->left->data = temp;
                minHeapify(bTRoot);
            }
            else
            {
                minHeapify(root->left);
            }
        }
        if (root->right != NULL)
        {
            if (root->right->data < root->data)
            {

                int temp = root->data;
                root->data = root->right->data;
                root->right->data = temp;
                minHeapify(bTRoot);
            }
            else
            {
                minHeapify(root->right);
            }
        }
    }
}

int main()
{

    insert(bTRoot, 51);
    minHeapify(bTRoot);

    insert(bTRoot, 80);
    minHeapify(bTRoot);

    insert(bTRoot, 79);
    minHeapify(bTRoot);

    insert(bTRoot, 18);
    minHeapify(bTRoot);

    insert(bTRoot, 32);
    minHeapify(bTRoot);

    insert(bTRoot, 89);
    minHeapify(bTRoot);

    insert(bTRoot, 74);
    minHeapify(bTRoot);

    insert(bTRoot, 12);
    minHeapify(bTRoot);

    preorderBHT(bTRoot);

    //               12
    //         18          32
    //     51      79    80    89
    // 85      74
    return 0;
}
