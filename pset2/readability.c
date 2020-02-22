#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int letters(string st);
int words(string st);
int sentences(string st);

int main(void)
{
    string str = get_string("ENTER YOUR TEXT: ");
    int n1 = letters(str);
    int n2 = words(str);
    int n3 = sentences(str);

    double L=(n1/n2)*100;
    double S=(n3/n2)*100;
    int i=round((0.0588*L)-(0.296*S)-15.8);

    if (i<1)
    {
        printf("Before Grade 1");
    }
    else if (i>=16)
    {
        printf("Grade 16+");
    }
    else 
    {
        printf("Grade %i\n", i);
    }
}

int letters(string st)
{
    int n=strlen(st);
    int count=0;
    for(int i=0;i<n;i++)
    {
        if ((st[i]>='a' && st[i]<='z') || (st[i]>='A' && st[i]<='Z'))
        {
            count++;
        }
    }
    return count;
}

int words(string st)
{
    int n=strlen(st);
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(isspace(st[i]))
        {
            count++;
        }
    }
    return count+1;
}
int sentences(string st)
{
    int n=strlen(st);
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(st[i]=='.'||st[i]=='!'||st[i]=='?')
        {
            count++;
        }
    }
    return count;
}
