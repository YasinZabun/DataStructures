#include <iostream>
using namespace std;

void DoubleProbing(int *hashTable, int hashTableLength, int *valuesToBeHashed, int valuesToBeHashedLength)
{
    if (valuesToBeHashedLength <= hashTableLength)
    {
        int indexToBeHashed;
        for (int i = 0; i < valuesToBeHashedLength; i++)
        {
            indexToBeHashed = valuesToBeHashed[i] % hashTableLength;
            if (hashTable[indexToBeHashed] == 0)
            {
                hashTable[indexToBeHashed] = valuesToBeHashed[i];
            }
            else
            {
                for (int j = 1; j <= hashTableLength; j++)
                {
                    // hash1(x)=x%n
                    // hash2(x)=1+x%(n-1)
                    // double hashing function = hash1(x)+1*hash(2) = (x%n + 1 * (1+x%(n-1))) % n
                    if (hashTable[(indexToBeHashed + i * (1 + valuesToBeHashed[i] % hashTableLength - 1)) % hashTableLength] == 0)
                    {
                        hashTable[(indexToBeHashed + i * (1 + valuesToBeHashed[i] % hashTableLength - 1)) % hashTableLength] = valuesToBeHashed[i];
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < hashTableLength; i++)
        {
            cout << hashTable[i] << " ";
        }
    }
    else
    {
        cout << "Missing request";
    }
}

int main()
{
    int hashTable[7] = {0, 0, 0, 0, 0, 0, 0};
    int valuesToBeHashed[5] = {23, 12, 45, 33, 58};
    DoubleProbing(hashTable, 7, valuesToBeHashed, 5);
    return 0;
}
