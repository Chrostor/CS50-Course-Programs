#include <stdio.h>
#include <cs50.h>

int main(void)
{
    for (int i = 65; i < 65 + 26; i++)
    {
        printf("%c is %i\n", i, i);
    }
}