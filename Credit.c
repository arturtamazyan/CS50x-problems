
#include <stdio.h>
#include <cs50.h>
#include<math.h>

int main(void)
{

    long card_number = get_long("Card number: ");

// second degit from last
    long last2 = card_number % (long)pow(10, 2) / 10 * 2 ;

//adding digits of 1digit and 2digit numbers
    long sum0 = last2 / 10 + last2 % 10;

    long last4 = card_number % (long)pow(10, 4) / (long)pow(10, 3) * 2;

    sum0 += last4 / 10 + last4 % 10;

    long last6 = card_number % (long)pow(10, 6) / (long)pow(10, 5) * 2;

    sum0 += last6 / 10 + last6 % 10;

    long last8 = card_number % (long)pow(10, 8) / (long)pow(10, 7) * 2;

    sum0 += last8 / 10 + last8 % 10;

    long last10 = card_number % (long)pow(10, 10) / (long)pow(10, 9) * 2;

    sum0 += last10 / 10 + last10 % 10;

    long last12 = card_number % (long)pow(10, 12) / (long)pow(10, 11) * 2;

    sum0 += last12 / 10 + last12 % 10;

    long last14 = card_number % (long)pow(10, 14) / (long)pow(10, 13) * 2;

    sum0 += last14 / 10 + last14 % 10;

    long last16 = card_number % (long)pow(10, 16) / (long)pow(10, 15) * 2;

    sum0 += last16 / 10 + last16 % 10;



//1st digit from last
    long last1 = card_number % 10;
//sum of digits
    long sum1 = last1;

    long last3 = card_number % (long)pow(10, 3) / (long)pow(10, 2);

    sum1 += last3;

    long last5 = card_number % (long)pow(10, 5) / (long)pow(10, 4);

    sum1 += last5;

    long last7 = card_number % (long)pow(10, 7) / (long)pow(10, 6);

    sum1 += last7;

    long last9 = card_number % (long)pow(10, 9) / (long)pow(10, 8);

    sum1 += last9;

    long last11 = card_number % (long)pow(10, 11) / (long)pow(10, 10);

    sum1 += last11;

    long last13 = card_number % (long)pow(10, 13) / (long)pow(10, 12);

    sum1 += last13;

    long last15 = card_number % (long)pow(10, 15) / (long)pow(10, 14);

    sum1 += last15;

    long sum = sum0 + sum1;




    if (sum % 10 == 0)
    {
        //checking first 2 digits of 16digit number
        long a = card_number / (long)pow(10, 14);

        //checking first 2 digits of 15digit number
        long b = card_number / (long)pow(10, 13);

        //checking first digit of 16 digit number
        long c = card_number / (long)pow(10, 15);

        //checking first digit of 13 digit number
        long d = card_number / (long)pow(10, 12);




        if (a == 51 || a == 52 || a == 53 || a == 54 || a == 55)
        {
            printf("MASTERCARD\n");
        }


        else if (b == 34 || b == 37)
        {
            printf("AMEX\n");
        }

        else if (c == 4 || (card_number / (long)pow(10, 13) == 0 && d == 4))
        {
            printf("VISA\n");
        }

        else
        {
            printf("INVALID\n");
        }

    }

    else
    {
         printf("INVALID\n");
    }


}
