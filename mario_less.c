#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
    
    //number of spaces in first raw
    int space = h - 1;

    //number of hashes in first raw
    int hash = 1;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < space; j++)
        {
            printf(" ");
        }

        space--;

        for (int j = 0; j < hash; j++)
        {
            printf("#");
        }

        hash++;

        printf("\n");
    }

}
