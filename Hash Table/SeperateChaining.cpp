#include <iostream>
#include <vector>
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

void SeperateChaining(vector<Node> hashTable, int hashTableLength, int *valuesToBeHashed, int valuesToBeHashedLength)
{
    for (int i = 0; i < hashTableLength; i++)
    {
        hashTable.push_back(Node(0));
    }
    int indexToBeHashed;
    for (int i = 0; i < valuesToBeHashedLength; i++)
    {
        indexToBeHashed = valuesToBeHashed[i] % hashTableLength;
        if (hashTable.at(indexToBeHashed).data == 0)
        {
            hashTable.at(indexToBeHashed).data = valuesToBeHashed[i];
        }
        else
        {
            Node *newNode = new Node(valuesToBeHashed[i]);
            Node *temp=&hashTable.at(indexToBeHashed);
            while (true)
            {
                if (temp->link == NULL)
                {
                    temp->link = newNode;
                    break;
                }
                temp = temp->link;
            }
        }
    }
    Node *temp = NULL;
    for (int i = 0; i < hashTable.size(); i++)
    {
        cout << hashTable.at(i).data << " ";
        temp = hashTable.at(i).link;
        while ((temp != NULL))
        {
            cout << " -> " << temp->data;
            temp = temp->link;
        }
        cout << endl;
    }
}

int main()
{
    vector<Node> hashTable;
    int valuesToBeHashed[25] = {67, 23, 12, 45, 56, 23, 87, 17, 71, 632, 65, 1, 97, 34, 24, 95, 34, 58, 60, 72, 36,27,92,20,100};
    SeperateChaining(hashTable, 7, valuesToBeHashed, 25);
    return 0;
}
