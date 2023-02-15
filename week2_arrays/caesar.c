#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{

    //declaring "fake key(string)" and real(int)
    string string_key = argv[1];

    int key;

    if (argc != 2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }

    for (int i = 0, n = strlen(string_key); i < n; i++)
    {
        if (isalpha(string_key[i]))
        {
            printf("Usage: ./caesar keyy \n");
            return 1;
        }
    }

    //converting string to int
    key = atoi(string_key);

    //get rid of redundant big number
    key = key % 26;

    string plain_text = get_string("Your text: ");

    for (int i = 0, n = strlen(plain_text); i < n; i++)
    {
        //for enciphering lowercase latters
        if (plain_text[i] >= 65 && plain_text[i] <= 90)
        {
            plain_text[i] += key;

            //if it goes beyond z
            if (plain_text[i] > 90)
            {
                plain_text[i] -= 26;
            }
        }

        //for enciphering uppercase latters
        if (plain_text[i] >= 97 && plain_text[i] <= 122)
        {
            //for using value of plain_text, becouse it can go beyond ASCII maximal value
            int x = plain_text[i];

            //this time first subtract than add
            if (x + key > 122)
            {
                plain_text[i] -= 26;
            }

            plain_text[i] += key;
        }

    }

    printf("ciphertext: %s\n", plain_text);
}

