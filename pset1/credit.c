#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long n;
    do                    // accepting input & check for negatives
    {
        n = get_long("Number: ");        
    }
    while (n < 0);
    int count = 0;
    
    long digits = n;
    while (digits > 0)
    {
        digits = digits / 10;
        count++;
    }
    int numbers[count];   // array to store all the numbers
    int sum_odd = 0;
    int sum_even = 0;  // sum of doubles of all alternate numbers second to last 
    digits = n;
    for (int i = 0; i < count; i++)
    {
        numbers[i] = digits % 10;
        digits = digits / 10;
        if (i % 2 == 1)                    // even number positions
        {
            if (numbers[i] * 2 >= 10)
            {
                sum_even += 1;
            }
            sum_even += (numbers[i] * 2) % 10;        // add mods by default & 1 more to numbers > 10
        }
        if (i % 2 == 0)                    // odd number positions
        {
            sum_odd += numbers[i];            // add odd numbers
        }
    }
    if ((sum_odd + sum_even) % 10 == 0)
    {
        if (count == 13 && numbers[12] == 4)
        {
            printf("VISA\n");
        }
        else if (count == 16 && numbers[15] == 4)
        {
            printf("VISA\n");
        }
        else if ((count == 15 && numbers[14] == 3) && (numbers[13] == 4 || numbers[13] == 7))
        {
            printf("AMEX\n");
        }
        else if ((count == 16 && numbers[15] == 5) && (numbers[14] >= 1 && numbers[14] <= 5))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
