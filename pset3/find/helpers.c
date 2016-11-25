/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 * First: Value being searched for.  Second: Array of values.  Third: Size of array
 */
bool search(int value, int values[], int n)
{
    int left = 0;
    int right = n - 1;
    bool found = false;
    int checked = 0;
    int runout = 0;
    
    while ((left != right) && (value != values[checked]) && runout < 20)
    {
        runout ++;
        checked = (left + right) / 2;
        printf("%i checked\n %i left\n %i right\n ", checked, left, right);
        
        if(left == (right -1))
        {
            if(values[left] == value || values[right] == value)
            {
                found = true;
                break;
            }
            else
            {
                found = false;
                break;
            }
        }
        if (value != values[checked])
        {
            if(value > values[checked])
            {
                left = checked + 1;
                printf("greater\n ");
            }
            else
            {
                right = checked - 1;
                printf("less\n ");
            }
        }
        else
        {
            found = true;
        }
    }
    printf("\n");
    return found;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    return;
}
