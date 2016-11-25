#include <cs50.h>
#include <stdio.h>

void sort(int values[], int n);

int main(void)
{
    int testArray[5] = {1, 3, 3, 4, 7};
    int arrayLength = 5;
    int arranged[5] = sort(testArray, arrayLength);
    for (int i = 0; i < arrayLength; i++)
    {
        printf("%i, ", arranged[i]);
    }
}

void sort(int values[], int n)
{
    int left;
    int right;
    for (int i = 0; i < n; i++)
    {
        
    }
}