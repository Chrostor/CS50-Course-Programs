#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convertCipher();
int offset = 0;

int main(int argc, string argv[])
{
    
    
    if(argc == 2){
        offset = atoi(argv[1]);
        if (offset > 26)
        {
        offset = offset % 26;
        }
        convertCipher();
    }
    else
    {
        printf("Error: did not use 1 argument\n");
        return 1;
    }
    printf("\n");
    return 0;
}

void convertCipher()
{
    printf("plaintext: ");
    // A to Z is 65-90
    // a to z is 97-122
    string a = get_string();
    printf("ciphertext: ");
    for (int i = 0; i < strlen(a); i++)
    {
        // capital letters
        if(a[i]>=65 && a[i]<=90)
        {
            // if the current letter plus the offset is higher than the index for capital letters
            if((a[i] + offset) > 90)
            {
                // then wrap back around to the start and print that character
                printf("%c", (a[i] + offset) - 26);
            }
            // otherwise, just print the character plus the offset
            else
            {
                printf("%c", a[i] + offset);
            }
        }
        // lowercase letters
        else if (a[i]>=97 && a[i]<=122)
        {
            // if the current letter plus the offset is higher than the index for lowercase letters
            if((a[i] + offset) > 122)
            {
                // then wrap back around to the start and print that character
                printf("%c", (a[i] + offset) - 26);
            }
            // otherwise, just print the character plus the offset
            else
            {
                printf("%c", a[i] + offset);
            }
        }
        else
        {
            printf("%c", a[i]);
        }
        
    }
}