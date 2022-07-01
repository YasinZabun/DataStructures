#include <iostream>
using namespace std;

bool isSorted(int (&array)[12])
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

void writeSortedArray(int (&sortedArray)[12])
{
    for (int i = 0; i < sizeof(sortedArray) / sizeof(sortedArray[0]); i++)
    {
        cout << sortedArray[i] << " ";
    }
}

void sort(int (&unsortedArray)[12])
{
    int temp;
    int lengthOfUnsortedArray = sizeof(unsortedArray) / sizeof(unsortedArray[0]);
    int indexOfLastUnsortedElement = lengthOfUnsortedArray - 2;

    while (!isSorted(unsortedArray))
    {
        for (int i = 0; i <= indexOfLastUnsortedElement; i++)
        {
            if (unsortedArray[i] > unsortedArray[i + 1])
            {
                temp = unsortedArray[i];
                unsortedArray[i] = unsortedArray[i + 1];
                unsortedArray[i + 1] = temp;
            }
        }
        indexOfLastUnsortedElement--;
    }
}
int main()
{
    int unsortedArray[] = {18, 29, 14, 14, 33, 14, 46, 23, 17, 7, 48, 18};
    sort(unsortedArray);
    writeSortedArray(unsortedArray);
    return 0;
}