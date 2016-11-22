#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = get_string();
    
    if(name[0] != ' '){  // if the first character is not a space
        printf("%c", toupper(name[0]));  // print the first character
    }
    
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        if(name[i] == ' ' &&        // if the current character is a space, and the next character is not
           name[i + 1] != ' ' &&    // and the next character is a letter
           isalpha(name[i + 1]))
        {
            printf("%c", toupper(name[i + 1]));
        }
    }
    
    printf("\n");
}