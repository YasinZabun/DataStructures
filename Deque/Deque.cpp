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
HeadAndTailOfNode *createDeque(int *arr, int size)
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
HeadAndTailOfNode *enqueueBack(HeadAndTailOfNode *headAndTailOfNode, int item)
{
    Node *newNode = new Node(item);
    headAndTailOfNode->tail->rlink = newNode;
    newNode->llink = headAndTailOfNode->tail;
    headAndTailOfNode->tail = newNode;
    return headAndTailOfNode;
}
HeadAndTailOfNode *enqueueFront(HeadAndTailOfNode *headAndTailOfNode, int item)
{
    Node *newNode = new Node(item);
    headAndTailOfNode->head->llink = newNode;
    newNode->rlink = headAndTailOfNode->head;
    headAndTailOfNode->head = newNode;
    return headAndTailOfNode;
}

HeadAndTailOfNode *dequeueBack(HeadAndTailOfNode *headAndTailOfNode)
{
    headAndTailOfNode->tail = headAndTailOfNode->tail->llink;
    headAndTailOfNode->tail->rlink = NULL;
    return headAndTailOfNode;
}
HeadAndTailOfNode *dequeueFront(HeadAndTailOfNode *headAndTailOfNode)
{
    headAndTailOfNode->head = headAndTailOfNode->head->rlink;
    headAndTailOfNode->head->llink = NULL;
    return headAndTailOfNode;
}
void writeDeque(Node *head)
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
    
    HeadAndTailOfNode *headAndTailOfNode = createDeque(items, sizeof(items) / sizeof(items[0]));
    writeDeque(headAndTailOfNode->head);
    
    headAndTailOfNode = enqueueBack(headAndTailOfNode, 90);
    writeDeque(headAndTailOfNode->head);
    
    headAndTailOfNode = enqueueFront(headAndTailOfNode, 100);
    writeDeque(headAndTailOfNode->head);

    headAndTailOfNode = dequeueFront(headAndTailOfNode);
    writeDeque(headAndTailOfNode->head);
    
    headAndTailOfNode = dequeueBack(headAndTailOfNode);
    writeDeque(headAndTailOfNode->head);
    
    return 0;
}
