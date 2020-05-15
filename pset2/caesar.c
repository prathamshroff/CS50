#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    string k = argv[1];
    //printf("%s", k);
    for (int i = 0; i < strlen(k); i++)
    {
        if (isdigit(k[i]) == 0)
        {
            printf("Usage: ./caesar key");
            return 1;
        }
    }
    int o = atoi(argv[1]) % 26;
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
            continue;
        }

        int ascii_offset = isupper(plaintext[i]) ? 65 : 97;

        int pi = plaintext[i] - ascii_offset;
        int ci = (pi + o) % 26;

        printf("%c", ci + ascii_offset);
    }
    printf("\n");
    return 0;
}