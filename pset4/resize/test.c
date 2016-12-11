#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(void)
{
    int mult = 3;
    int nums[] = {1, 2, 3, 4};
    int numLen = sizeof(nums) / sizeof(int);
    
    printf("nums length: %i\n", numLen);
    
    int dub[mult * numLen];
    
    int dubLen = sizeof(dub) / sizeof(int);
    
    printf("dub length: %i\n", dubLen);
    for (int i = 0; i < numLen; i++)
    {
        for(int j = i * mult; j < (i * mult) + mult; j++)
        {
            dub[j] = nums[i];
        }
    }
    for(int i = 0; i < dubLen; i++)
    {
        printf("%i", dub[i]);
    }
    
    
    
}