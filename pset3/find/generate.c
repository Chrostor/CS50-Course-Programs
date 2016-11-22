/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, string argv[])
{
    // if input arguments are not two or three, then print error message and return 1 for bad program exit
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // create a new integer and give it the value of the command line input
    int n = atoi(argv[1]);

    // if the user inputs two values, then seed the random buffer with the value given in the second argument
    // otherwise, seed the random buffer with the time, since it always changes
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));
    }
    else
    {
        srand48((long) time(NULL));
    }

    // in a loop, generate the amount of random numbers requested by the user.  On each iteration, multiply the result of
    // drand48() by the limit so it's not just a 0.0 to 1.0 number
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
