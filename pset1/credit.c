#include <cs50.h>
#include <stdio.h>
#include <math.h>

bool validSum(long long n, int length);
int digCount(long long n);
bool validInput(int n);
void cardType(long long ccn, int digCount);
int startDig(long long ccn, int digCount);


int main(void)
{
    printf("Number: ");
    long long ccn = get_long_long();
    if(ccn < 1 || digCount(ccn) > 16)
    {
        printf("INVALID\n");
    } 
    else
    {
        if(validInput(digCount(ccn)))
        {
            if(validSum(ccn, digCount(ccn)))
            {
              cardType(ccn, digCount(ccn)); 
            } 
            else
            {
                printf("WTF");
            }
        } 
        else
        {
        printf("INVALID\n");
        } 
    }
    
    return 0;
}

/* Valid card if 
    1) Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products' digits together.
    2) Add the sum to the sum of the digits that weren’t multiplied by 2.
    3) If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
    4) valid number counts 13, 15, 16
    
    Finding places
    Ones        input % 10
    Tens        (input / 10) % 10
    Hundreds    (input / 100) % 10
    etc...
    
    Verify full number
    input / (input % *number of digits in input, found through iteration*)
*/

bool validSum(long long n, int length)
{
    // in a loop, take every other digit starting with second to last, multiply by 2, then added to a sum
    // in another loop, take every other digit starting with last, and add to a sum
    // add the sums of those two together
    // check if last digit is zero
    long long ccn = n;
    int ccnLen = length / 2 + 1;
    int sumOdd = 0;
    int sumEven = 0;
    int total = 0;
    while (ccnLen > 0){
        sumEven = sumEven + (ccn % 10);
        if (sumOdd + (2 * ((ccn / 10) % 10)) > 9){
            int a = 2 * ((ccn / 10) % 10);
            int b = a % 10;
            int c = (a / 10) % 10;
            int d = b + c;
            sumOdd = sumOdd + d;
            
        } else 
        {
            sumOdd = sumOdd + (2 *((ccn / 10) % 10));
        }
        ccn = ccn / 100;
        ccnLen--;
        //printf("sumOdd %i sumEven %i total %i\n", sumOdd, sumEven, sumOdd + sumEven);
    }
    total = sumOdd + sumEven;
    if (total % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
   
}

int digCount(long long n)
{
    long long x = n;
    int numLen = 0;
    while (x > 0)
    {
        numLen++;
        x = x / 10;
    }
    return numLen;
}

bool validInput(int n)
{
    if (n == 13 || n == 15 || n == 16)
    {
        return true;
    } 
    else
    {
        return false;
    }
}

void cardType(long long ccn, int digCount)
{
    int bNum = startDig(ccn, digCount);
    if(bNum == 34 || bNum == 37)
    {
        printf("AMEX\n");
    } else if (bNum == 51 || bNum == 52 || bNum == 53 || bNum == 54 || bNum == 55)
    {
        printf("MASTERCARD\n");
    }
    else if(bNum == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID");
    }
}

int startDig(long long ccn, int digCount)
{
    
    if (digCount == 15)
    {
        return ((ccn / 10000000000000) % 100);  // 15 digits
    }
    else if (digCount == 13)
    {
        return ((ccn / 1000000000000) % 10);  // 13 digits
    }
    else if (((ccn / 1000000000000000) % 10) == 4 && (digCount == 16))
    {
        return 4;
    }
    else if(((ccn / 1000000000000000) % 10) != 4  && (digCount == 16))
    {
        return ((ccn / 100000000000000) % 100);
    }
    else
    {
        return digCount;
    }
}

// American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers. 
// American Express numbers all start with 34 or 37; MasterCard numbers all start with 51, 52, 53, 54, or 55; and Visa numbers all start with 4