/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4 || atoi(argv[1]) > 99 || atoi(argv[1]) < 0)
    {
        fprintf(stderr, "Usage: ./resize n (positive whole number less than 100) infile outfile\n");
        return 1;
    }
    
    // remember multiplier
    int mult = atoi(argv[1]);
    
    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // determine padding required for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;        
    
    // determine new padding required after multiplier
    int newPadding = (4 - ((mult * bi.biWidth) * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // grab old width and height values before they 
    // are updated for the headers
    int inBiWidth = bi.biWidth;
    int inBiHeight = abs(bi.biHeight);
 
    // modify outfile's BITMAPINFOHEADER
    bi.biWidth = bi.biWidth * mult;
    bi.biHeight = bi.biHeight * mult;
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) +
                        newPadding) * abs(bi.biHeight);

    // modify outfile's BITMAPFILEHEADER
    bf.bfSize = bi.biSizeImage +
                sizeof(BITMAPFILEHEADER) +
                sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    
    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0; i < inBiHeight; i++)
    {
        // create storage array for storing doubled pixels
        RGBTRIPLE tripUp[inBiWidth];
        
        // fill array with current scanline from infile
        fread(&tripUp, sizeof(RGBTRIPLE), inBiWidth, inptr);

        // print out the temporary array, plus padding, n times
        
        for (int a = 0; a < mult; a++) 
        {
            for (int j = 0; j < inBiWidth; j++) // for the width of the infile scanline
            {
            
                for(int k = 0; k < mult; k++) // for n times
                {
                
                    // write the pixel to the outfile
                    fwrite(&tripUp[j], sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            for (int k = 0; k < newPadding; k++)
                {
                    fputc(0x00, outptr);
                }
        }    
        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
