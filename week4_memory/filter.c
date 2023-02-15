#include "helpers.h"
#include <math.h>


void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            image[i][j].rgbtBlue = average;

            image[i][j].rgbtGreen = average;

            image[i][j].rgbtRed = average;
        }
    }
    return;
}


void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);


            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }



            image[i][j].rgbtBlue = sepiaBlue;

            image[i][j].rgbtGreen = sepiaGreen;

            image[i][j].rgbtRed = sepiaRed;
        }
    }
    return;
}


void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE reversed[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            reversed[i][width - 1 - j] = image[i][j];
        }

    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
             image[i][j] = reversed[i][j];
        }

    }

    return;
}


void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blured[height][width];
    //rgbtBlue
    //rgbtGreen
    //rgbtRed

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int h = i - 1; h < i + 2; h++)
            {
                for (int g = j - 1; g < i + 2; g++)
                {
                    blured[i][j].rgbtBlue = image[h][g].rgbtBlue + 
                }
            }
        }
    }
    return;
}
