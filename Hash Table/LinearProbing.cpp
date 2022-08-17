#include <iostream>
using namespace std;

void LinearProbing(int *hashTable, int hashTableLength, int *valuesToBeHashed, int valuesToBeHashedLength)
{
    if (valuesToBeHashedLength <= hashTableLength)
    {
        cout<<hashTable[2];
        int step;
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
                while (true)
                {
                    if(indexToBeHashed>=hashTableLength){
                        indexToBeHashed=0;
                    }else{
                        if(hashTable[indexToBeHashed]==0){
                            hashTable[indexToBeHashed]=valuesToBeHashed[i];
                            break;
                        }
                        indexToBeHashed++;
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
    int valuesToBeHashed[7] = {23, 12, 45, 56, 23, 87, 17};
    LinearProbing(hashTable, 7, valuesToBeHashed, 7);
    return 0;
}
