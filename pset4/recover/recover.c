#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEX unsigned char
#define JPEG_BLOCK 512

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr,"Usage: ./recover file_to_recover\n");
        return 1;
    }
    
    // remember filename
    char *inptr = argv[1];
    
    FILE *infile = fopen(inptr, "r");
    if(infile == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", inptr);
        return 2;
    }
    
    // create a buffer for jpeg blocks of 512 bytes
    HEX buffer[JPEG_BLOCK];
    
    // create variables for use in main loop
    int foundfirst = 0;
    char *outfn = malloc(8);
    int nameInc = 000;
    FILE *outfile;
    
    // main loop
    while(fread(&buffer, 1, JPEG_BLOCK, infile) == JPEG_BLOCK)
    {
        // check first four bytes for new file
        if( buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
            {
                // the first four indicate the beginning of a file, so check if this is the first
                if(foundfirst == 0)
                {
                    // 1st new file found. 1) Set foundfirst to true 2) Update out file name to correct format
                    // 3) Open a new file 4) Write buffer to file
                    foundfirst = 1;
                    sprintf(outfn, "%03i.jpg\n", nameInc);
                    outfile = fopen(outfn, "w");
                    fwrite(&buffer, 1, JPEG_BLOCK, outfile);
                    
                } else {
                    // A new file was found, but not the first one.  1) Close last file 2) Increment file name 
                    // 3) Update out file name 4) Open new file 5) Write buffer to file
                    fclose(outfile);
                    nameInc++;
                    sprintf(outfn, "%03i.jpg\n", nameInc);
                    outfile = fopen(outfn, "w");
                    fwrite(&buffer, 1, JPEG_BLOCK, outfile);
                }
                
            } else {
                // the first four DO NOT indicate the biggining of a file.  Check if the first file has been found
                if(foundfirst == 1)
                {
                    // this is part of a JPEG.  Write the buffer to the file
                    fwrite(&buffer, 1, JPEG_BLOCK, outfile);
                } else {
                    // this is before the first file.  Ignore these bytes
                }
                
            }
    }
    
    // if the foundfirst boolean ever becomes true, then we need to close up the last opened outfile
    if(foundfirst == 0)
    {
        fclose(outfile);
    }
    
    // close infile
    fclose(infile);
    
    // free the memory used for the out file name
    free(outfn);
  
    // success
    return 0;
}