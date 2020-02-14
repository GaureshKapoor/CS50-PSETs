#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int convert(string s);

const char *c = NULL;

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar\n");
        return 1;
    }

    int val = atoi(argv[1]);

    if (val < 0)
    {
        printf("Usage: ./caesar\n");
        return 1;
    }
    else 
    {
        string str = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0, n = strlen(str); i < n; i++)
        {
            if islower(str[i])
            {
                printf("%c", (((str[i] + val) - 97) % 26) + 97);
            }
            else if isupper(str[i])
            {
                printf("%c", (((str[i] + val) - 65) % 26) + 65);
            }
            else
            {
                printf("%c", str[i]);
            }   
        }
        printf("\n");
        return 0;
    }
}
