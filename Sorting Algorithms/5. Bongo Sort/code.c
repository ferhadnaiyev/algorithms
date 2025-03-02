#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bongoSort(int array[], int arrayLength);
void shuffle(int array[], int arrayLength);
int isSorted(int array[], int n);
void printArray(int array[], int size);

int main(void)
{
    int arr[] = {23, 15, 22, 34, 11, 83, 45, 50};
    int arrLength = sizeof(arr) / sizeof(arr[0]);
    srand(time(NULL));
    printf("Given array is: \n");
    printArray(arr, arrLength);
    bongoSort(arr, arrLength);
    printf("sorted array is: \n");
    printArray(arr, arrLength);
}

void bongoSort(int array[], int arrayLength)
{
    do
    {
        shuffle(array, arrayLength);
        // remove comments for see shuffled arrays
        // printf("shuffle array \n");
        // printArray(array, arrayLength);

    } while (!isSorted(array, arrayLength));
}

void shuffle(int array[], int arrayLength)
{

    int newIndex, temp;

    for (int i = 0; i < arrayLength - 1; i++)
    {
        newIndex = rand() % arrayLength;
        temp = array[i];
        array[i] = array[newIndex];
        array[newIndex] = temp;
    }
}

int isSorted(int array[], int n)
{
    while (--n >= 1)
    {
        if (array[n] < array[n - 1])
        {
            return 0;
        }
    }
    return 1;
}
void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}
