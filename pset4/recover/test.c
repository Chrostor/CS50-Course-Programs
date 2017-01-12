#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEX unsigned char
#define JPEG_BLOCK 512

int main(void)
{
    char *ff = malloc(8);
    int ni = 000;
    FILE *outfile;
    sprintf(ff, "%03i.jpg\n", ni);
    
    outfile = fopen(ff, "w");
    ni++;
    printf("%s", ff);
    sprintf(ff, "%03i.jpg\n", ni);
    outfile = fopen(ff, "w");
    printf("%s", ff);
    free(ff);
    fclose(outfile);
    
    

    return 0;
}