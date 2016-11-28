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
    bool run = true;
    if(value == values[0] || value == values[n-1])
    {
        found = true;
        run = false;
    }
    while ((left != right) && (value != values[checked]) && run == true)
    {
        if(values[0] == value)
        {
            found = true;
            break;
        }
        checked = (left + right) / 2;
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
            }
            else
            {
                right = checked - 1;
            }
        }
        else
        {
            found = true;
        }
    }
    return found;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    bool swapped = true;
    int left;
    int right;
    while (swapped == true)
    {
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
            }
        }
    }
}
