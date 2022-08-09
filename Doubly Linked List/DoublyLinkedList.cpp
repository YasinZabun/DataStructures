#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *rlink;
    Node *llink;
    Node(int value)
    {
        data = value;
        rlink = NULL;
        llink = NULL;
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
HeadAndTailOfNode *createDLL(int *arr, int size)
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *previousNode = NULL;
    for (int i = 0; i < size; i++)
    {
        Node *newNode = new Node(arr[i]);
        if (i == size - 1)
        {
            tail = newNode;
        }
        if (head == NULL)
        {
            head = newNode;
        }
        if (previousNode != NULL)
        {
            newNode->llink = previousNode;
            previousNode->rlink = newNode;
        }
        previousNode = newNode;
    }
    return new HeadAndTailOfNode(head, tail);
}
Node *insert(Node *tail, int item)
{
    Node *newNode = new Node(item);
    tail->rlink = newNode;
    newNode->llink = tail;
    tail = newNode;
    return tail;
}

HeadAndTailOfNode *remove(HeadAndTailOfNode *headAndTailOfNode, int data)
{
    Node *temp = headAndTailOfNode->head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            if (headAndTailOfNode->head == temp)
            {
                headAndTailOfNode->head = temp->rlink;
                headAndTailOfNode->head->llink = NULL;
                delete temp;
                break;
            }
            if (headAndTailOfNode->tail == temp)
            {
                headAndTailOfNode->tail = temp->llink;
                headAndTailOfNode->tail->rlink = NULL;
                delete temp;
                break;
            }
            temp->rlink->llink = temp->llink;
            temp->llink->rlink = temp->rlink;
            delete temp;
            break;
        }
        temp = temp->rlink;
    }
    return headAndTailOfNode;
}

void writeDLL(Node *head)
{
    Node *temp = head;
    if (temp->rlink == NULL)
    {
        cout << temp->data << " ";
    }
    else
    {

        while (temp->rlink != NULL)
        {
            cout << temp->data << " ";
            temp = temp->rlink;
        }
        cout << temp->data << " ";
    }
    cout << endl;
}

int main()
{
    int items[] = {85, 51, 80, 79, 18, 32, 89, 74, 12};
    HeadAndTailOfNode *headAndTailOfNode = createDLL(items, sizeof(items) / sizeof(items[0]));
    writeDLL(headAndTailOfNode->head);
    headAndTailOfNode->tail = insert(headAndTailOfNode->tail, 90);
    writeDLL(headAndTailOfNode->head);
    headAndTailOfNode = remove(headAndTailOfNode, 79);
    writeDLL(headAndTailOfNode->head);
    return 0;
}
