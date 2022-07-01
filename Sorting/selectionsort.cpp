#include <iostream>
using namespace std;

bool isSorted(int (&array)[15])
{
    for (int i = 0; i < sizeof(array) / sizeof(array[0]) - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }
    return true;
}

void writeSortedArray(int (&sortedArray)[15])
{
    for (int i = 0; i < sizeof(sortedArray) / sizeof(sortedArray[0]); i++)
    {
        cout << sortedArray[i] << " ";
    }
}

void sort(int (&unsortedArray)[15])
{
    int temp;
    int lengthOfUnsortedArray = sizeof(unsortedArray) / sizeof(unsortedArray[0]);
    int smallestElementIndex;
    int conditionalElement;
    for (int i = 0; i < lengthOfUnsortedArray; i++)
    {
        conditionalElement = unsortedArray[i];
        for (int j = i + 1; j < lengthOfUnsortedArray; j++)
        {
            if (conditionalElement > unsortedArray[j])
            {
                conditionalElement = unsortedArray[j];
                smallestElementIndex = j;
            }
        }
        if (smallestElementIndex != 0)
        {
            temp = unsortedArray[smallestElementIndex];
            unsortedArray[smallestElementIndex] = unsortedArray[i];
            unsortedArray[i] = temp;
            smallestElementIndex = 0;
        }
    }
}
int main()
{
    int unsortedArray[] = {7, 32, 43, 10, 21, 11, 1, 34, 34, 41, 42, 10, 28, 31, 27};
    sort(unsortedArray);
    writeSortedArray(unsortedArray);
    return 0;
}