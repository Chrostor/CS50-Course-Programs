#include <cs50.h>
#include <stdio.h>

bool searchmethodA(int value, int values[], int n);
bool searchmethodB(int value, int values[], int n);

int main(void)
{
    int testValue = 5;
    int testArray[5] = {1, 3, 4, 6, 12};
    int testArrayLength = 5;
    bool found = searchmethodB(testValue, testArray, testArrayLength);
    printf("%i\n", found);
    
}

bool searchmethodA(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    bool result = false;
    for(int i = 0; i < n - 1; i++)
    {
        if(value == values[i])
        {
            result = true;
            break;
        }
        else
        {
            result = false;
        }
    }
    return result;
}

bool searchmethodB(int value, int values[], int n)
{
    int left = 0;
    int right = n - 1;
    bool found = false;
    int checked = 0;
    
    while ((left != right) && (value != values[checked]))
    {
        checked = (right-left)/2;
       
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