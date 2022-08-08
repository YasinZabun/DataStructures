#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *link;
    Node(int value)
    {
        data = value;
        link = NULL;
    }
};
class HeadAndTailOfNode
{
public:
    Node *head;
    Node *tail;
    HeadAndTailOfNode(Node *headNode, Node *tailNode)
    {
        head = headNode;
        tail = tailNode;
    }
};
HeadAndTailOfNode *createStack(int *arr, int size)
{
    Node *head = NULL;
    Node *tail = NULL;
    for (int i = 0; i < size; i++)
    {
        Node *newNode = new Node(arr[i]);
        if (i == 0)
        {
            tail = newNode;
        }
        if (head != NULL)
        {
            newNode->link = head;
        }
        head = newNode;
    }
    return new HeadAndTailOfNode(head, tail);
}
int peek(Node *head)
{
    return head->data;
}
Node *push(Node *head, int item)
{
    Node *newNode = new Node(item);
    newNode->link = head;
    head = newNode;
    return head;
}

HeadAndTailOfNode *pop(HeadAndTailOfNode *headAndTailOfNode)
{
    if (headAndTailOfNode->head == headAndTailOfNode->tail)
    {
        headAndTailOfNode->head->link = NULL;
        headAndTailOfNode->tail->link = NULL;
        return headAndTailOfNode;
    }
    Node *temp = headAndTailOfNode->head;
    Node *previousNode = NULL;
    while (temp != headAndTailOfNode->tail)
    {
        previousNode = temp;
        if (temp->link != NULL)
            temp = temp->link;
    }
    previousNode->link = NULL;
    headAndTailOfNode->tail = previousNode;
    delete temp;
    return headAndTailOfNode;
}

void writeStack(Node *head)
{
    Node *temp = head;
    if (temp->link == NULL)
    {
        cout << temp->data<<" ";
    }
    else
    {

        while (temp->link != NULL)
        {
            cout << temp->data<<" ";
            temp = temp->link;
        }
        cout << temp->data<<" ";
    }
}

int main()
{
    int items[] = {82, 98, 48, 27, 9};
    HeadAndTailOfNode *headAndTailOfNode = createStack(items, sizeof(items) / sizeof(items[0]));
    headAndTailOfNode->head = push(headAndTailOfNode->head, 6);
    writeStack(headAndTailOfNode->head);
    headAndTailOfNode=pop(headAndTailOfNode);
    cout << endl;
    writeStack(headAndTailOfNode->head);
    return 0;
}
