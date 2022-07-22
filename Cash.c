#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int cents;
    do
    {
         cents = get_int("Cents: ");
    }
    while(cents < 1 || cents > 99) ;






    int coin_25 = cents / 25;

    int coin_10 = (cents - 25 * coin_25) / 10;

    int coin_5 = (cents - 25 * coin_25 - 10 * coin_10) / 5;

    int coin_1 = cents - 25 * coin_25 - 10 * coin_10 - 5 * coin_5;

    printf("%i-25cents\n%i-10cents\n%i-5cents\n%i-1cents", coin_25, coin_10, coin_5, coin_1);


}
