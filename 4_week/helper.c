#include "helpers.h"
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;

            int grayscale = (r + g + b) / 3;
            image[i][j].rgbtRed = grayscale;
            image[i][j].rgbtGreen = grayscale;
            image[i][j].rgbtBlue = grayscale;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;

            int _r = (0.393 * r) + (0.769 * g) + (0.189 * b);
            int _g = (0.349 * r) + (0.686 * g) + (0.168 * b);
            int _b = (0.272 * r) + (0.534 * g) + (0.131 * b);

            if (_r > 255){
                image[i][j].rgbtRed = 255;
            } else {
                image[i][j].rgbtRed = _r;
            }

            if (_g > 255){
                image[i][j].rgbtGreen = 255;
            } else {
                image[i][j].rgbtGreen = _g;
            }

            if (_b > 255){
                image[i][j].rgbtBlue = 255;
            } else {
                image[i][j].rgbtBlue = _b;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width/2; j++){
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;

            int r_ = image[i][width-j-1].rgbtRed;
            int g_ = image[i][width-j-1].rgbtGreen;
            int b_ = image[i][width-j-1].rgbtBlue;

            image[i][width-j-1].rgbtRed = r;
            image[i][width-j-1].rgbtGreen = g;
            image[i][width-j-1].rgbtBlue = b;

            image[i][j].rgbtRed = r_;
            image[i][j].rgbtGreen = g_;
            image[i][j].rgbtBlue = b_;

        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 1; i < height - 1; i++){
        for(int j = 1; j < width - 1; j++){
            int sumR = image[i-1][j+1].rgbtRed +
                       image[i+0][j+1].rgbtRed +
                       image[i+1][j+1].rgbtRed +
                       image[i-1][j+0].rgbtRed +
                       image[i+0][j+0].rgbtRed +
                       image[i+1][j+0].rgbtRed +
                       image[i-1][j-1].rgbtRed +
                       image[i+0][j-1].rgbtRed +
                       image[i+1][j-1].rgbtRed;

            int sumG = image[i-1][j+1].rgbtGreen +
                       image[i+0][j+1].rgbtGreen +
                       image[i+1][j+1].rgbtGreen +
                       image[i-1][j+0].rgbtGreen +
                       image[i+0][j+0].rgbtGreen +
                       image[i+1][j+0].rgbtGreen +
                       image[i-1][j-1].rgbtGreen +
                       image[i+0][j-1].rgbtGreen +
                       image[i+1][j-1].rgbtGreen;

            int sumB = image[i-1][j+1].rgbtBlue +
                       image[i+0][j+1].rgbtBlue +
                       image[i+1][j+1].rgbtBlue +
                       image[i-1][j+0].rgbtBlue +
                       image[i+0][j+0].rgbtBlue +
                       image[i+1][j+0].rgbtBlue +
                       image[i-1][j-1].rgbtBlue +
                       image[i+0][j-1].rgbtBlue +
                       image[i+1][j-1].rgbtBlue;

            image[i][j].rgbtRed = sumR/9;
            image[i][j].rgbtGreen = sumG/9;
            image[i][j].rgbtBlue = sumB/9;
        }
    }
    return;
}

