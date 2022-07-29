#include <iostream>
using namespace std;

int getLength(int *array)
{
    int i = 0;
    while (array[i] != '\0')
    {
        i++;
    }
    return i;
}

void writeSortedArray(int *sortedArray)
{
    int arrayLength = getLength(sortedArray);
    for (int i = 0; i < arrayLength; i++)
    {
        cout << sortedArray[i] << " ";
    }
}

int *skip(int *array, int firstIndex, int lastIndex)
{
    int *toBeReturnedArray = new int[lastIndex - firstIndex + 1];
    int i = 0;
    for (; i < (lastIndex - firstIndex + 1); i++)
    {
        toBeReturnedArray[i] = array[i + firstIndex];
    }
    toBeReturnedArray[i] = '\0';
    return toBeReturnedArray;
}

int *mergeSort(int *unsortedArray)
{
    int lengthOfUnsortedArray = getLength(unsortedArray);
    if (lengthOfUnsortedArray > 2)
    {

        int *leftUnsortedArray = mergeSort(skip(unsortedArray, 0, lengthOfUnsortedArray % 2 == 0 ? lengthOfUnsortedArray / 2 - 1 : lengthOfUnsortedArray / 2));
        int *rightUnsortedArray = mergeSort(skip(unsortedArray, lengthOfUnsortedArray % 2 == 0 ? lengthOfUnsortedArray / 2 : lengthOfUnsortedArray / 2 + 1, lengthOfUnsortedArray - 1));

        int toBeMergedLeftLength = getLength(leftUnsortedArray);
        int toBeMergedRightLength = getLength(rightUnsortedArray);
        int mergedLength = toBeMergedLeftLength + toBeMergedRightLength;
        int *mergedArray = new int[mergedLength];
        int leftSortedIndex = 0;
        int rightSortedIndex = 0;
        int i = 0;

        for (; i < mergedLength; i++)
        {
            if (rightSortedIndex < toBeMergedRightLength && leftSortedIndex < toBeMergedLeftLength)
            {
                if (leftUnsortedArray[leftSortedIndex] > rightUnsortedArray[rightSortedIndex])
                {
                    mergedArray[i] = rightUnsortedArray[rightSortedIndex];
                    rightSortedIndex++;
                }
                else if (leftSortedIndex < toBeMergedLeftLength)
                {
                    mergedArray[i] = leftUnsortedArray[leftSortedIndex];
                    leftSortedIndex++;
                }
            }
            else
            {
                if (rightSortedIndex < toBeMergedRightLength)
                {
                    mergedArray[i] = rightUnsortedArray[rightSortedIndex];
                    rightSortedIndex++;
                }
                else
                {
                    mergedArray[i] = leftUnsortedArray[leftSortedIndex];
                    leftSortedIndex++;
                }
            }
        }

        delete leftUnsortedArray;
        delete rightUnsortedArray;

        mergedArray[i] = '\0';

        return mergedArray;
    }
    else
    {
        int temp;
        if (lengthOfUnsortedArray > 1 && unsortedArray[0] != unsortedArray[1] && unsortedArray[0] > unsortedArray[1])
        {
            temp = unsortedArray[0];
            unsortedArray[0] = unsortedArray[1];
            unsortedArray[1] = temp;
        }
        return unsortedArray;
    }
}

int main()
{
    int *unsortedArray = new int[12]{12, 31, 25, 8, 32, 17, 40, 42, 1, 100, 42, '\0'};
    int *mergeSortedArray = mergeSort(unsortedArray);
    writeSortedArray(mergeSortedArray);
    delete unsortedArray;
    delete mergeSortedArray;
    return 0;
}