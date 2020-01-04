#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    do                    // accepting input & check for negatives
    {
        dollars = get_float("Change owed: ");        
    }
    while (dollars < 0); 
    
    int cents = round(dollars * 100);    // just to remove ambiguity
    int coins = 0;           // counter variable
    
    while (cents > 0)
    {
        if (cents >= 25) 
        {
            coins++;
            cents -= 25;
        }
        else if (cents >= 10)
        {
            coins++;
            cents -= 10;
        }
        else if (cents >= 5)
        {
            coins++;
            cents -= 5;
        }
        else        // doesn't need 1 as there is no alternative
        {
            coins++;
            cents -= 1;
        }
    }
    printf("%i", coins);
    printf("\n");        // new line for neatness
}
