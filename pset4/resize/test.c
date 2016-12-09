#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(void)
{
    int mult = 2;
    int temp = (4 - ((mult * 2) * sizeof(RGBTRIPLE)) % 4) % 4;
    printf("size %i", temp);
}