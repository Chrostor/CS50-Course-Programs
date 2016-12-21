#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(void)
{
    int mult = 2;
    mult++;
    int temp = (4 - (5 * sizeof(RGBTRIPLE)) % 4) % 4;
    printf("size %i", temp);
}