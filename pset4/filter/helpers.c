#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float a = image[h][w].rgbtRed;
            float b = image[h][w].rgbtBlue;
            float c = image[h][w].rgbtGreen;
            int i = round((a + b + c)/3);

            i %= 255;
            if (i % 255 == 0)
                {}
            else
            {
                image[h][w].rgbtRed = i;
                image[h][w].rgbtBlue = i;
                image[h][w].rgbtGreen = i;
            }
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float r = image[h][w].rgbtRed;
            float b = image[h][w].rgbtBlue;
            float g = image[h][w].rgbtGreen;

            int sepiaRed = round(.393 * r + .769 * g + .189 * b);
            int sepiaGreen = round(.349 * r + .686 * g + .168 * b);
            int sepiaBlue = round(.272 * r + .534 * g + .131 * b);

            int fr;
            int fb;
            int fg;

            if(sepiaRed > 255)
                fr = 255;
            else
                fr = sepiaRed;

            if(sepiaBlue > 255)
                fb = 255;
            else
                fb = sepiaBlue;

            if(sepiaGreen > 255)
                fg = 255;
            else
                fg = sepiaGreen;

            image[h][w].rgbtRed = fr;
            image[h][w].rgbtBlue = fb;
            image[h][w].rgbtGreen = fg;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //check if height is odd or even number
    if (height % 2 == 0 || width % 2 == 0)
    {
        for (int i = 0; i < height; i++)
        {
            for (int x = 0; x < width/2; x++)
            {
                int widback = (width-x) - 1;
                int switchgreen = image[i][x].rgbtGreen;
                int switchblue = image[i][x].rgbtBlue;
                int switchred = image[i][x].rgbtRed;

                image[i][x].rgbtGreen = image[i][widback].rgbtGreen;
                image[i][x].rgbtBlue = image[i][widback].rgbtBlue;
                image[i][x].rgbtRed = image[i][widback].rgbtRed;

                image[i][widback].rgbtGreen = switchgreen;
                image[i][widback].rgbtBlue = switchblue;
                image[i][widback].rgbtRed = switchred;
            }
        }
    }
    else
        for (int i = 0; i < height; i++)
            {
                for (int x = 0; x < (width/2)+1; x++)
                {
                    int widback = (width-x) - 1;

                    int switchgreen = image[i][x].rgbtGreen;
                    int switchblue = image[i][x].rgbtBlue;
                    int switchred = image[i][x].rgbtRed;

                    image[i][x].rgbtGreen = image[i][widback].rgbtGreen;
                    image[i][x].rgbtBlue = image[i][widback].rgbtBlue;
                    image[i][x].rgbtRed = image[i][widback].rgbtRed;

                    image[i][widback].rgbtGreen = switchgreen;
                    image[i][widback].rgbtBlue = switchblue;
                    image[i][widback].rgbtRed = switchred;
                }
            }


    return;
}

// Blur image

void blur(int height, int width, RGBTRIPLE image[height][width])
{
   RGBTRIPLE ogImage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ogImage[i][j] = image[i][j];
        }
    }

    for (int i = 0, red, green, blue, counter; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red = green = blue = counter = 0;

            if (i >= 0 && j >= 0)
            {
                red += ogImage[i][j].rgbtRed;
                green += ogImage[i][j].rgbtGreen;
                blue += ogImage[i][j].rgbtBlue;
                counter++;
            }
            if (i >= 0 && j - 1 >= 0)
            {
                red += ogImage[i][j - 1].rgbtRed;
                green += ogImage[i][j - 1].rgbtGreen;
                blue += ogImage[i][j - 1].rgbtBlue;
                counter++;
            }
            if ((i >= 0 && j + 1 >= 0) && (i >= 0 && j + 1 < width))
            {
                red += ogImage[i][j + 1].rgbtRed;
                green += ogImage[i][j + 1].rgbtGreen;
                blue += ogImage[i][j + 1].rgbtBlue;
                counter++;
            }
            if (i - 1 >= 0 && j >= 0)
            {
                red += ogImage[i - 1][j].rgbtRed;
                green += ogImage[i - 1][j].rgbtGreen;
                blue += ogImage[i - 1][j].rgbtBlue;
                counter++;
            }
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                red += ogImage[i - 1][j - 1].rgbtRed;
                green += ogImage[i - 1][j - 1].rgbtGreen;
                blue += ogImage[i - 1][j - 1].rgbtBlue;
                counter++;
            }
            if ((i - 1 >= 0 && j + 1 >= 0) && (i - 1 >= 0 && j + 1 < width))
            {
                red += ogImage[i - 1][j + 1].rgbtRed;
                green += ogImage[i - 1][j + 1].rgbtGreen;
                blue += ogImage[i - 1][j + 1].rgbtBlue;
                counter++;
            }
            if ((i + 1 >= 0 && j >= 0) && (i + 1 < height && j >= 0))
            {
                red += ogImage[i + 1][j].rgbtRed;
                green += ogImage[i + 1][j].rgbtGreen;
                blue += ogImage[i + 1][j].rgbtBlue;
                counter++;
            }
            if ((i + 1 >= 0 && j - 1 >= 0) && (i + 1 < height && j - 1 >= 0))
            {
                red += ogImage[i + 1][j - 1].rgbtRed;
                green += ogImage[i + 1][j - 1].rgbtGreen;
                blue += ogImage[i + 1 ][j - 1].rgbtBlue;
                counter++;
            }
            if ((i + 1 >= 0 && j + 1 >= 0) && (i + 1 < height && j + 1 < width))
            {
                red += ogImage[i + 1][j + 1].rgbtRed;
                green += ogImage[i + 1][j + 1].rgbtGreen;
                blue += ogImage[i + 1][j + 1].rgbtBlue;
                counter++;
            }

            image[i][j].rgbtRed = round(red / (counter * 1.0));
            image[i][j].rgbtGreen = round(green / (counter * 1.0));
            image[i][j].rgbtBlue = round(blue / (counter * 1.0));
        }
    }

    return;
}