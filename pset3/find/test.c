#include <cs50.h>
#include <stdio.h>

bool searchmethodA(int value, int values[], int n);
bool searchmethodB(int value, int values[], int n);

int main(void)
{
    int testValue = 41;
    int testArray[3] = {41, 43, 44};
    int testArrayLength = 3;
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
    int runout = 0;
    bool run = true;
    printf("first %i last %i\n", values[0], values[n-1]);
    if(value == values[0] || value == values[n-1])
    {
        found = true;
        run = false;
        printf("stopped");
    }
    
    while ((left != right) && (value != values[checked]) && runout < 5 && run == true)
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