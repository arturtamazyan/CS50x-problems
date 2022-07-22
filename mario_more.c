#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    do
    {

      height = get_int("Height: ");

    }
    while (8 < height || height < 1);

// for(h) loop / decreasing "height -1"
    int t = height - 1;

// for(j) loop / increasing "1"
    int a = 1;

// for(g) loop/ increasing "1"
    int b = 1;

   for (int i = 0; i < height; i++)
   {

      for (int j = 0; j < a; j++)
      {

           for (int h = 0; h < t; h++ )
           {
              printf(" ");
           }

           for (int g = 0; g < b; g++)
           {
               printf("#");
           }

           printf("  ");

           for (int g = 0; g < b; g++)
           {
               printf("#");
           }



           for (int h = 0; h < t; h++ )
           {
              printf(" ");
           }

           t--;
           b++;

      }
      printf("\n");

   }

}
