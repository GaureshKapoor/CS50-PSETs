#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float f;
    do
    {
        f = get_float("Change in Dollars:");
    }
    while (f < 0);
    float dollars = f;
    float cents = round(dollars * 100);
    printf("Change in Cents: %.2f\n", cents);
    int count = 0;
    
    float quarter = 25;
    while (cents >= quarter)
    {
        count++;
        cents -= quarter;
    }
    
    float dimes= 10;
    while (cents >= dimes)
    {
        count++;
        cents-=dimes;
    }  
    
    float nickel=5;
    while (cents >= nickel)
    {
        count++;
        cents -= nickel;
    }  
    
    float pennies=1;
    while (cents >= pennies)
    {
        count++;
        cents -= pennies;
    }
    printf("Number of coins used: %i\n", count);
}
