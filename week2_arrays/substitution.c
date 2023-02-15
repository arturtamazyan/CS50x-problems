#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int validate(string key);
string make_lowercase(string key);
string incipher(string plaintext, string key);


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }


    string key = argv[1];


//if the check is 1 the key is invalid if the check is 0 the key is valid
    int check =  validate(key);




    if (check == 1)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    if (check == 10)
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }
    if (check == 100)
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }


    key = make_lowercase(key);

    string plaintext = get_string("plaintext: ");

    string ciphertext = incipher(plaintext, key);

    printf("ciphertext: %s\n", ciphertext);

}






int validate(string key)
{
//for returning 0 or not
    //int c = 0;
//if the length is not 26 return 1
    if (strlen(key) != 26)
    {

        return 1;
    }


// if the length is 26 check are all the letters non-repeated
    else
    {
//compare  letters with each other

        for (int i = 0, b = 1; i < strlen(key); i++, b++)
        {
            if (b < strlen(key))
            {

                if (key[i] == key[b])
                {
                    return 10;
                }

            }
        }
    }


//checking are the all characters  letters
    for (int i = 0; i < strlen(key); i++)
    {
        if (key[i] < 65 || (key[i] > 90 && key[i] < 97) || key[i] > 122)
        {
            //c++;
            return 100;
        }
    }

    return 0;
}


string make_lowercase(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        key[i] = tolower(key[i]);
    }

    return key;
}



string incipher(string plaintext, string key)
{
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (plaintext[i] >= 65 && plaintext[i] <= 90)
        {
            plaintext[i] = toupper(key[plaintext[i] - 65]);
        }

        else if (plaintext[i] >= 97 && plaintext[i] <= 122)
        {
            plaintext[i] = key[plaintext[i] - 97];
        }

    }
    return plaintext;
}


