#include <cs50.h>
#include <stdio.h>

int get_height(string prompt);

int main(void)
{
    int height = get_height("Height: ");
    for (int i=0; i<height; i++)
    {
        for (int k=height-i; k>1; k--)
        {
            printf(" ");
        }
        for (int j=0; j<=i; j++)
        {
            printf("#");

        }
        printf("\n");
    }
}

int get_height(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);
    }
    while (n<1 || n>8);
    return n;
}
