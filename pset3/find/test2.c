#include <cs50.h>
#include <stdio.h>

void sort(int values[], int n);

int main(void)
{
    int testArray[5] = {7, 7, 3, 2, 1};
    int arrayLength = 5;
    sort(testArray, arrayLength);
    for (int i = 0; i < arrayLength; i++)
    {
        printf("%i, ", testArray[i]);
    }
}

void sort(int values[], int n)
{
    int runout = 0;  //testing purposes
    bool swapped = true;
    int left;
    int right;
    while (swapped == true && runout < 30)
    {
        runout ++;// testing purposes
        swapped = false;
        for (int i = 0; i < n - 1; i++)
        {
        left = values[i];
        right = values[i+1];
        if(left > right)
            {
                values[i] = right;
                values[i+1] = left;
                swapped = true;
                printf(" %i swapped ", swapped);
            }
        }
    }
    printf(" %i runout ", runout);
    
}