#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage ./recover filename");

        return 1;
    }
    FILE *card = fopen(argv[1], "r");

    uint8_t buffer[512];

    int jpeg_count = -1;

    char *jpeg_name = malloc(8);

    FILE *image;



    while (fread(buffer, 1, 512, card) == 512 && jpeg_count < 0)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            jpeg_count++;

            sprintf(jpeg_name, "%03i.jpg", jpeg_count);

            image = fopen(jpeg_name, "w");

            if (image == NULL)
            {
                return 1;
            }

            fwrite(buffer, 512, 1, image);

        }

    }

    //not to lose last reading when false
    fwrite(buffer, 512, 1, image);



    while (fread(buffer, 1, 512, card) == 512)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            fclose(image);

            jpeg_count++;

            sprintf(jpeg_name, "%03i.jpg", jpeg_count);

            image = fopen(jpeg_name, "w");

        }

        fwrite(buffer, 512, 1, image);

    }

    fclose(image);
    free(jpeg_name);
    fclose(card);




}
