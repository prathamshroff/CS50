#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    for (int line = 1; line <= height; line++)
    {
        for (int space = height - line; space > 0; space--)
        {
            printf(" ");
        }
        for (int hash = 1; hash <= line; hash++)
        {
            printf("#");
        }
        printf("  ");
        for (int hash = 1; hash <= line; hash++)
        {
            printf("#");
        }
        printf("\n");
    }
}
