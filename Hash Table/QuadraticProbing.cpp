#include <iostream>
using namespace std;

void QuadraticProbing(int *hashTable, int hashTableLength, int *valuesToBeHashed, int valuesToBeHashedLength)
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
                //This loop might be infinit. Because this algorithm is missed. Better algorithm could be 
                //Let P(x) = x2, keep the table size a prime number > 3 and also α(Max load factor) <= ½.
                //Let P(x) = (x2 + x)/2, keep the table size a power of two.
                //Let P(x) = (-1x)*x2, keep the table size a prime number N where N ≡ 3 mod 4.
                for(int j=1;j<=hashTableLength;j++){
                    if(hashTable[(indexToBeHashed+j*j)%hashTableLength]==0){
                        hashTable[(indexToBeHashed+j*j)%hashTableLength]=valuesToBeHashed[i];
                        break;
                    }
                }
            }
        }
        for(int i=0;i<hashTableLength;i++){
            cout<<hashTable[i]<<" ";
        }
    }
    else
    {
        cout << "Missing request";
    }
}

int main()
{
    int hashTable[7]={0,0,0,0,0,0,0};
    int valuesToBeHashed[5] = {23, 12, 45,33,58};
    QuadraticProbing(hashTable, 7, valuesToBeHashed, 5);
    return 0;
}
