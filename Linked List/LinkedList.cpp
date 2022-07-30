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
HeadAndTailOfNode *createLinkedList(int *arr, int size)
{
    Node *head = NULL;
    Node *tail = NULL;
    for (int i = size - 1; i >= 0; i--)
    {
        Node *newNode = new Node(arr[i]);
        if (i == size - 1)
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
Node *insert(Node *tail, int item)
{
    Node *newNode = new Node(item);
    tail->link = newNode;
    tail = newNode;
    return tail;
}

HeadAndTailOfNode *remove(HeadAndTailOfNode *headAndTailOfNode, int item)
{
    Node *temp = headAndTailOfNode->head;
    Node *previosNode = NULL;
    while (temp->link != NULL)
    {
        if (temp->data == item)
        {
            if (temp == headAndTailOfNode->head)
            {
                headAndTailOfNode->head = temp->link;
            }
            else
            {
                if (temp->link != NULL)
                {

                    previosNode->link = temp->link;
                }
                else
                {
                    headAndTailOfNode->tail = previosNode;
                }
            }
            delete temp;
            break;
        }
        if (temp->link != NULL)
        {
            previosNode = temp;
            temp = temp->link;
        }
    }
    if (temp->data == item)
    {
        headAndTailOfNode->tail = previosNode;
        headAndTailOfNode->tail->link = NULL;
        delete temp;
    }
    return headAndTailOfNode;
}

void writeLinkedList(Node *head)
{
    Node *temp = head;
    if (temp->link == NULL)
    {
        cout << temp->data;
    }
    else
    {

        while (temp->link != NULL)
        {
            cout << temp->data;
            temp = temp->link;
        }
        cout << temp->data;
    }
}

int main()
{
    int items[] = {1, 2, 3, 4, 5};
    HeadAndTailOfNode *headAndTailOfNode = createLinkedList(items, sizeof(items) / sizeof(items[0]));
    headAndTailOfNode->tail = insert(headAndTailOfNode->tail, 6);
    writeLinkedList(headAndTailOfNode->head);
    remove(headAndTailOfNode, 2);
    cout << endl;
    writeLinkedList(headAndTailOfNode->head);
    return 0;
}
