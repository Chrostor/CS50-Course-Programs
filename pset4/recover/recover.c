#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover file_to_recover\n");
        return 1;
    }
    
    // remember filename
    char *infile = argv[1];
    
    FILE *inptr = fopen(infile, "r");
    if(inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    
    
    
    
    // close infile
    fclose(inptr);
    
    // success
    return 0;
}