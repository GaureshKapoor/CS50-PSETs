#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

bool check(int a, string s[]);
int convert(string s);

int main(int argc, string argv[])
{
    bool b = check(argc, argv, size);
    if (b == true && argc == 2)
    {
        int value = convert (argv[1]);
        printf(" %i",value);
    }
    else
    {
        printf("Usage: ./caesar");
    }
}

bool check(int a, string s[])
{
    for (int i = 0; i < a; i++)
    {
        if (a == 1 && (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int convert(string s)
{
    int val = atoi(s);
    return val;
}
