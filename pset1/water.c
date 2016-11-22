#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("minutes: ");
    int x = get_int();
    printf("bottles: %i\n", x * 192 / 16);
}