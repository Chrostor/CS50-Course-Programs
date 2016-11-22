#include <cs50.h>
#include <stdio.h>

void pHash(int n);
void pSpace(int n);
void makePyramid(int n);

int main(void)
{
    int x = get_int();
    makePyramid(x);
}

void pHash(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}

void pSpace(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void makePyramid(int n)
{
    int spaces = n-1; /* number of spaces starts at input minus 1 */
    int hashes = n-spaces; /*number of hashes starts at input minus the number of spaces */
    for (int i = 0; i < n; i++)
    {
        /* each round of the loop  
        1) print number of spaces 
        2) print number of hashes 
        3) print 2 spaces 
        4) print number of hashes 
        5) print number of spaces
        6) print a return line
        7) decrement number of spaces
        8) increment number of hashes */
        
        pSpace(spaces);
        pHash(hashes);
        pSpace(2);
        pHash(hashes);
        pSpace(spaces);
        printf("\n");
        spaces --;
        hashes ++;
    }
    
}