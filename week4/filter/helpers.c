#include "helpers.h"
#include <math.h>

// Convert image to grayscale
int compare(int i, int j);
void swap(BYTE* a, BYTE* b);

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int avg_rgb = round((pixel.rgbtBlue + pixel.rgbtGreen + pixel.rgbtRed) / 3.0);
            image[i][j].rgbtBlue = avg_rgb;
            image[i][j].rgbtGreen = avg_rgb;
            image[i][j].rgbtRed = avg_rgb;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            image[i][j].rgbtRed = compare(round(0.393 * pixel.rgbtRed + 0.769 * pixel.rgbtGreen + 0.189 * pixel.rgbtBlue), 255);
            image[i][j].rgbtGreen = compare(round(0.349 * pixel.rgbtRed + 0.686 * pixel.rgbtGreen + 0.168 * pixel.rgbtBlue), 255);
            image[i][j].rgbtBlue = compare(round(0.272 * pixel.rgbtRed + 0.534 * pixel.rgbtGreen + 0.131 * pixel.rgbtBlue), 255);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            swap(&image[i][j].rgbtRed, &image[i][width-j-1].rgbtRed);
            swap(&image[i][j].rgbtGreen, &image[i][width-j-1].rgbtGreen);
            swap(&image[i][j].rgbtBlue, &image[i][width-j-1].rgbtBlue);
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int blurRed = 0;
            int blurGreen = 0;
            int blurBlue = 0;
            float n = 0;
            for (int p = i - 1; p <= i + 1; p++)
            {
                for (int q = j - 1; q <= j + 1; q++)
                {
                    if (p < 0 || q < 0 || p >= height || q >= width)
                    {
                        continue;
                    }
                    blurRed += image[p][q].rgbtRed;
                    blurGreen += image[p][q].rgbtGreen;
                    blurBlue += image[p][q].rgbtBlue;
                    n += 1;
                }
            }
            copy[i][j].rgbtRed = round(blurRed/n);
            copy[i][j].rgbtGreen = round(blurGreen/n);
            copy[i][j].rgbtBlue = round(blurBlue/n);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}

int compare(int i, int j)
{
    if (i > j)
    {
        return j;
    }
    else
    {
        return i;
    }
}

void swap(BYTE* a, BYTE* b)
{
    BYTE tmp = *a;
    *a = *b;
    *b = tmp;
}