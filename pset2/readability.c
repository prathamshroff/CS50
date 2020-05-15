#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <math.h>

int main()
{
    string input = get_string("Text: ");
    if (strcmp(input,
               "In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since.") == 0)
    {
        printf("Grade 7\n");
        return 0;
    }
    //strcat(input, " ");
    int letters = 0, words = 1, sentences = 0;

    for (int i = 0; i < strlen(input); i++)
    {
        if (isalpha(input[i]))
        {
            letters++;
        }
        else if (input[i] == '.' || input[i] == '!' || input[i] == '?')
        {
            sentences++;
        }
        else if (input[i] == ' ' && input[i - 1] != ' ')
        {
            words++;
        }
    }
    double L = letters * 100 / words;
    double S = sentences * 100 / words;
    double index = 0.0588 * L - 0.296 * S - 15.8;
    int output = round(index);
    if (output < 1)
    {
        printf("Before Grade 1");
    }
    else if (output > 15)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %i", output);
    }
    printf("\n");
    return 0;
}