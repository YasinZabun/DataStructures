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
HeadAndTailOfNode *createQueue(int *arr, int size)
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
int peekFront(Node *head)
{
    return head->data;
}
int peekBack(Node *tail)
{
    return tail->data;
}
Node *enQueue(Node *tail, int item)
{
    Node *newNode = new Node(item);
    tail->link=newNode;
    tail = newNode;
    return tail;
}

HeadAndTailOfNode *deQueue(HeadAndTailOfNode *headAndTailOfNode)
{
    if (headAndTailOfNode->head == headAndTailOfNode->tail)
    {
        headAndTailOfNode->head->link = NULL;
        headAndTailOfNode->tail->link = NULL;
        return headAndTailOfNode;
    }

    Node *temp = headAndTailOfNode->head;
    headAndTailOfNode->head = temp->link;
    delete temp;
    return headAndTailOfNode;
}

void writeQueue(Node *head)
{
    Node *temp = head;
    if (temp->link == NULL)
    {
        cout << temp->data << " ";
    }
    else
    {

        while (temp->link != NULL)
        {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << temp->data << " ";
    }
    cout<<endl;
}

int main()
{
    int items[] = {2, 77, 6, 43, 76, 89, 56};
    HeadAndTailOfNode *headAndTailOfNode = createQueue(items, sizeof(items) / sizeof(items[0]));
    writeQueue(headAndTailOfNode->head);
    headAndTailOfNode->tail = enQueue(headAndTailOfNode->tail, 90);
    writeQueue(headAndTailOfNode->head);
    headAndTailOfNode = deQueue(headAndTailOfNode);
    writeQueue(headAndTailOfNode->head);
    int frontPeek = peekFront(headAndTailOfNode->head);
    int backPeek = peekBack(headAndTailOfNode->tail);
    cout << "peek from front is " << frontPeek << " and peek from back is " << backPeek;
    return 0;
}
