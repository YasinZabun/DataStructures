#include <iostream>
using namespace std;

void WriteSortedArray(int (&sortedArray)[15])
{
    for (int i = 0; i < sizeof(sortedArray) / sizeof(sortedArray[0]); i++)
    {
        cout << sortedArray[i] << " ";
    }
}
void swap(int (&unsortedArray)[15], int indexOfLeftElement, int indexOfRightElement)
{
    if (unsortedArray[indexOfLeftElement] < unsortedArray[indexOfRightElement])
    {
        unsortedArray[indexOfLeftElement] += unsortedArray[indexOfRightElement];
        unsortedArray[indexOfRightElement] = unsortedArray[indexOfLeftElement] - unsortedArray[indexOfRightElement];
        unsortedArray[indexOfLeftElement] -= unsortedArray[indexOfRightElement];
    }
    else
    {
        unsortedArray[indexOfRightElement] += unsortedArray[indexOfLeftElement];
        unsortedArray[indexOfLeftElement] = unsortedArray[indexOfRightElement] - unsortedArray[indexOfLeftElement];
        unsortedArray[indexOfRightElement] -= unsortedArray[indexOfLeftElement];
    }
}
void Sort(int (&unsortedArray)[15])
{
    int lengthOfUnsortedArray = sizeof(unsortedArray) / sizeof(unsortedArray[0]);

    for (int i = 0; i < lengthOfUnsortedArray - 1; i++)
    {
        if (unsortedArray[i] > unsortedArray[i + 1])
        {
            swap(unsortedArray, i, i + 1);

            for (int j = i; j > 0; j--)
            {
                if (unsortedArray[j] < unsortedArray[j - 1])
                {
                    swap(unsortedArray, j, j - 1);
                }
                else
                {
                    break;
                }
            }
        }
    }
}

int main()
{
    int unsortedArray[] = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    Sort(unsortedArray);
    WriteSortedArray(unsortedArray);
    return 0;
}