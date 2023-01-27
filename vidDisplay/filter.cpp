#include <stdio.h>
#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "vidDisplay.h"

// Toggle the filter mode on/off. When a filter mode is toggled off, the program enters "color" mode
void toggleFilterMode(std::string *currentMode, std::string tobeMode)
{
    if (*currentMode == tobeMode)
    {
        printf("%s mode -> color mode\n", (*currentMode).c_str());
        *currentMode = "color";
    }
    else
    {
        printf("%s mode -> %s mode\n", (*currentMode).c_str(), tobeMode.c_str());
        *currentMode = tobeMode;
    }
}

// Displays grayscale using cv::cvtColor function.
int mainGrayscale(cv::Mat *src, cv::Mat *dest)
{
    cv::cvtColor(*src, *dest, cv::COLOR_BGRA2GRAY);
    return 0;
}

// Displays alternate grayscale by changing each pixel to the average value of each color channel
// Returns 0 on success
int greyscale(cv::Mat &src, cv::Mat &dst)
{
    for (int i = 0; i < src.rows; i++) // For each row
    {
        cv::Vec3b *rptr_src = src.ptr<cv::Vec3b>(i);  // rptr_src is a pointer to a row of pixels at the src image
        cv::Vec3b *rptr_dest = dst.ptr<cv::Vec3b>(i); // rptr_dest is a pointer to a row of pixels at the dest image

        for (int j = 0; j < src.cols; j++) // For each Column in the row...
        {
            // get average Color of each channel.
            double avgColor = (rptr_src[j][0] + rptr_src[j][1] + rptr_src[j][2]) / 3;
            // Assign a Vec3b object to the row pointer of the dest image
            rptr_dest[j] = cv::Vec3b(avgColor, avgColor, avgColor);
        }
    }
    return 0;
}

// Display a Gaussian filter for one Mat
int blur5x5(cv::Mat &src, cv::Mat &dst)
{
    double filter[5] = {1, 2, 4, 2, 1};
    double filterSum = 10; // the sum of the filter values
    cv::Mat interimImage = src.clone();
    // cv::Mat interimImage = cv::Mat::zeros(src.size(), src.type()); // Create placeholder for the output

    // APPLY COLUMN 1X5 filter to src image
    for (int i = 2; i < src.rows - 2; i++) // For each row
    {
        // Create pointers to src_row and dest_row
        cv::Vec3b *rptr_src_0 = src.ptr<cv::Vec3b>(i);          // points to row i
        cv::Vec3b *rptr_dst_0 = interimImage.ptr<cv::Vec3b>(i); // points at row i

        for (int j = 2; j < src.cols - 2; j++) // for each column (i.e., each pixel)
        {
            // Update the pixel
            // For each color channel
            for (int c = 0; c < 3; c++)
            {
                rptr_dst_0[j][c] = (filter[0] / filterSum * (rptr_src_0 - 2)[j][c]) +
                                   (filter[1] / filterSum * (rptr_src_0 - 1)[j][c]) + (filter[2] / filterSum * (rptr_src_0)[j][c]) +
                                   (filter[3] / filterSum * (rptr_src_0 + 1)[j][c]) + (filter[4] / filterSum * (rptr_src_0 + 2)[j][c]);
            }
        }
    }

    // APPLY ROW 5X1 filter to interim Image
    for (int i = 2; i < src.rows - 2; i++) // For each row
    {
        // Create pointers to src_row and dest_row
        cv::Vec3b *rptr_src_0 = interimImage.ptr<cv::Vec3b>(i); // points to row i
        cv::Vec3b *rptr_dst_0 = dst.ptr<cv::Vec3b>(i);          // points at row i

        for (int j = 2; j < src.cols - 2; j++) // for each column (i.e., each pixel)
        {
            // Update the pixel...
            // For each color channel
            for (int c = 0; c < 3; c++)
            {
                // APPLY THE FILTER
                rptr_dst_0[j][c] = (filter[0] / filterSum * rptr_src_0[j - 2][c]) +
                                   (filter[1] / filterSum * rptr_src_0[j - 1][c]) + (filter[2] / filterSum * rptr_src_0[j][c]) +
                                   (filter[3] / filterSum * rptr_src_0[j + 1][c]) + (filter[4] / filterSum * rptr_src_0[j + 2][c]);
            }
        }
    }
    return 0;
}

// Sobel X 3X3 Filter
// parameters are Vec3b
int sobelX3x3(cv::Mat &src, cv::Mat &dst)
{
    // Create images using 16 bit unsigned short data type
    cv::Mat image, interimImage, finalImage;
    src.convertTo(image, CV_16SC3);
    src.convertTo(interimImage, CV_16SC3);
    src.convertTo(finalImage, CV_16SC3);

    short filter[3] = {-1, 0, 1};
    // For each row in image
    for (int i = 2; i < image.rows; i++)
    {
        // Create pointers to image and interimImage rows
        cv::Vec3s *rptr_image = image.ptr<cv::Vec3s>(i);          // original image in greyscale
        cv::Vec3s *rptr_interim = interimImage.ptr<cv::Vec3s>(i); // interim image with one transformation done

        // For each col in image (i.e., for each pixel)
        for (int j = 2; j < image.cols; j++)
        {
            // for each color channel
            for (int chan = 0; chan < 3; chan++)
            {
                short newVal = 0;           // new color value
                for (int r = 0; r < 3; r++) // for each item of filter
                {

                    newVal += (filter[r] * rptr_image[j - 1 + r][chan]) / 1; // add up the newVal
                }
                rptr_interim[j][chan] = newVal;
            }
        }
    }
    short filter2[3] = {1, 2, 1};

    // For each row in image
    for (int i = 2; i < image.rows; i++)
    {
        // Create pointers to interimImage and finalImage rows
        cv::Vec3s *rptr_interim = interimImage.ptr<cv::Vec3s>(i);
        cv::Vec3s *rptr_final = finalImage.ptr<cv::Vec3s>(i);

        // For each col in image (i.e., for each pixel)
        for (int j = 2; j < image.cols; j++)
        {
            // for each color channel
            for (int chan = 0; chan < 3; chan++)
            {
                short newVal = 0;           // new color value
                for (int r = 0; r < 3; r++) // for each item of filter
                {

                    newVal += (filter2[r] * rptr_interim[j + (image.cols * (r - 1))][chan]) / 2; // add up the newVal
                    // newVal += (filter2[r] * (rptr_interim - 1 + r)[j][chan]) / 2; // add up the newVal
                }
                // newVal = newVal < 0 ? 0 : newVal > 255 ? 255
                //                                        : newVal;
                rptr_final[j][chan] = newVal;
            }
        }
    }
    finalImage.convertTo(dst, CV_16S);
    return 0;
};

int sobelY3x3(cv::Mat &src, cv::Mat &dst)
{
    // Create images using 16 bit unsigned short data type
    cv::Mat image, interimImage, finalImage; // original (image), interimImage is after fist pass of 1X3 filter, finalImage is after 2nd pass of 1X3 filter
    src.convertTo(image, CV_16SC3);
    src.convertTo(interimImage, CV_16SC3);
    src.convertTo(finalImage, CV_16SC3);

    short filter[3] = {1, 2, 1};
    // For each row in image
    for (int i = 2; i < image.rows; i++)
    {
        // Create pointers to image and interimImage rows
        cv::Vec3s *rptr_image = image.ptr<cv::Vec3s>(i);          // original image in greyscale
        cv::Vec3s *rptr_interim = interimImage.ptr<cv::Vec3s>(i); // interim image with one transformation done

        // For each col in image (i.e., for each pixel)
        for (int j = 2; j < image.cols; j++)
        {
            // for each color channel
            for (int chan = 0; chan < 3; chan++)
            {
                short newVal = 0;           // new color value
                for (int r = 0; r < 3; r++) // for each item of filter
                {

                    newVal += (filter[r] * rptr_image[j + r - 1][chan]) / 2; // add up the newVal
                }
                rptr_interim[j][chan] = newVal;
            }
        }
    }
    short filter2[3] = {-1, 0, 1};

    // For each row in image
    for (int i = 2; i < image.rows; i++)
    {
        // Create pointers to interimImage and finalImage rows
        cv::Vec3s *rptr_interim = interimImage.ptr<cv::Vec3s>(i);
        cv::Vec3s *rptr_final = finalImage.ptr<cv::Vec3s>(i);

        // For each col in image (i.e., for each pixel)
        for (int j = 2; j < image.cols; j++)
        {
            // for each color channel
            for (int chan = 0; chan < 3; chan++)
            {
                short newVal = 0;           // new color value
                for (int r = 0; r < 3; r++) // for each item of filter
                {

                    newVal += (filter2[r] * rptr_interim[j + (image.cols * (r - 1))][chan]) / 1; // add up the newVal
                }
                // Constrain the values to between 0 and 255
                // newVal = newVal < 0 ? 0 : newVal > 255 ? 255
                //                                        : newVal;
                rptr_final[j][chan] = newVal;
            }
        }
    }
    finalImage.convertTo(dst, CV_16S);
    return 0;
};

int magnitude(cv::Mat &sx, cv::Mat &sy, cv::Mat &dst)
{
    // Instantiate final image to hold the calculated image coming from sx and sy
    cv::Mat finalImage;
    sx.convertTo(finalImage, CV_16SC3);

    for (int i = 2; i < sx.rows; i++) // For each row...
    {
        // Get pointers
        cv::Vec3s *rptr_sx = sx.ptr<cv::Vec3s>(i);
        cv::Vec3s *rptr_sy = sy.ptr<cv::Vec3s>(i);
        cv::Vec3s *rptr_final = finalImage.ptr<cv::Vec3s>(i);

        for (int j = 2; j < sx.cols; j++) // For each col...
        {
            for (int c = 0; c < 3; c++) // for each color channel...
            {
                rptr_final[j][c] = std::sqrt(rptr_sx[j][c] * rptr_sx[j][c] + rptr_sy[j][c] * rptr_sy[j][c]);
            }
        }
    }

    // Convert to CV_8UC3
    finalImage.convertTo(dst, CV_8UC3);
    return 0;
}

// Parameters "src" and "dst" are type CV_8U
int blurQuantize(cv::Mat &src, cv::Mat &dst, int levels)
{
    // blur the image using gaussian
    int u = blur5x5(src, src); // Blur "src" Mat

    // For each row
    for (int i = 2; i < src.rows; i++) // For each row...
    {
        // Get pointers
        cv::Vec3b *rptr_src = src.ptr<cv::Vec3b>(i);
        cv::Vec3b *rptr_dst = dst.ptr<cv::Vec3b>(i);
        for (int j = 2; j < src.cols; j++) // For each column...
        {
            for (int c = 0; c < 3; c++) // For each color channel...
            {
                int b = 255 / levels;
                int newColor = rptr_src[j][c] / b * b;
                rptr_dst[j][c] = newColor;
            }
        }
    }
    return 0;
}

int cartoon(cv::Mat &src, cv::Mat &dst, int levels, int magThreshold)
{
    cv::Mat sx, sy, grad, quant;
    // 1. Calculate gradient magnitude
    int w = sobelX3x3(src, sx);
    int y = sobelY3x3(src, sy);
    int z = magnitude(sx, sy, grad);

    // 2. Blur and quantize the image -> output to "quant"
    src.convertTo(quant, CV_8U);              // Instantiate "quant"
    int x = blurQuantize(src, quant, levels); // Update "quant"

    // 3. Set pixels to black if they are larger than threshold
    for (int i = 2; i < quant.rows - 2; i++) // For each row
    {
        // Get pointer
        cv::Vec3b *rptr_grad = grad.ptr<cv::Vec3b>(i);   // Gradient image
        cv::Vec3b *rptr_quant = quant.ptr<cv::Vec3b>(i); // Quantized image
        cv::Vec3b *rptr_dst = dst.ptr<cv::Vec3b>(i);     // Output
        for (int j = 2; j < quant.cols - 2; j++)         // for each column
        {
            for (int c = 0; c < 3; c++) // for each color channel
            {

                rptr_dst[j][c] = rptr_grad[j][c] > magThreshold ? 0 : rptr_quant[j][c]; // update dst
            }
        }
    }
    return 0;
}

// Output a negative image
// Parameters are both of type CV_8U
int negative(cv::Mat &src, cv::Mat &dst)
{
    // for each row
    for (int i = 2; i < src.rows - 2; i++)
    {
        // get pointers
        cv::Vec3b *rptr_src = src.ptr<cv::Vec3b>(i);
        cv::Vec3b *rptr_dst = dst.ptr<cv::Vec3b>(i);
        // for each col
        for (int j = 0; j < src.cols - 2; j++)
        {
            // Negative = 255 - image value for each color channel
            rptr_dst[j][0] = 255 - rptr_src[j][0];
            rptr_dst[j][1] = 255 - rptr_src[j][1];
            rptr_dst[j][2] = 255 - rptr_src[j][2];
        }
    }
    return 0;
}

// Helper function that calculates the median.
uchar median(uchar arr[], int size)
{
    std::sort(arr, arr + size);
    if (size % 2 != 0)
        return (uchar)arr[size / 2];
    return (uchar)(arr[(size - 1) / 2] + arr[size / 2]) / 2.0;
}

// Extension: Median filter to smooth out blemishes
// 5X5 filter that sets the dst pixel equal to the median value of all pixels in the 5X5 mask
int smooth5x5(cv::Mat &src, cv::Mat &dst)
{
    // For each row...
    for (int i = 2; i < src.rows - 2; i++)
    {
        // Get pointers
        cv::Vec3b *rptr_src = src.ptr<cv::Vec3b>(i);
        cv::Vec3b *rptr_dst = dst.ptr<cv::Vec3b>(i);
        // For each column...
        for (int j = 2; j < src.cols - 2; j++)
        {
            // For each color channel
            for (int c = 0; c < 3; c++)
            {
                // Define the 5X5 mask
                uchar mask[25] = {rptr_src[j - 2 * src.cols - 2][c], rptr_src[j - 2 * src.cols - 1][c], rptr_src[j - 2 * src.cols][c], rptr_src[j - 2 * src.cols + 1][c], rptr_src[j - 2 * src.cols + 2][c],
                                  rptr_src[j - src.cols - 2][c], rptr_src[j - src.cols - 1][c], rptr_src[j - src.cols][c], rptr_src[j - src.cols + 1][c], rptr_src[j - src.cols + 2][c],
                                  rptr_src[j - 2][c], rptr_src[j - 1][c], rptr_src[j][c], rptr_src[j + 1][c], rptr_src[j + 2][c],
                                  rptr_src[j + src.cols - 2][c], rptr_src[j + src.cols - 1][c], rptr_src[j + src.cols][c], rptr_src[j + src.cols + 1][c], rptr_src[j + src.cols + 2][c],
                                  rptr_src[j + 2 * src.cols - 2][c], rptr_src[j + 2 * src.cols - 1][c], rptr_src[j + 2 * src.cols][c], rptr_src[j + 2 * src.cols + 1][c], rptr_src[j + 2 * src.cols + 2][c]};

                // Find the median of the 5X5 maks
                rptr_dst[j][c] = median(mask, 25);
            }
        }
    }
    return 0;
}

// Extension: Function to update the colors displayed based on 3 trackpads
// trackbars (Blue, Green, Red) will control the threshold values for when original color values are preserved vs. converted to 0.
int colorMinimums(cv::Mat &src, cv::Mat &dst, uchar bVal, uchar gVal, uchar rVal)
{
    // For each row
    for (int i = 0; i < src.rows; i++)
    {
        // set pointers
        cv::Vec3b *rptr_src = src.ptr<cv::Vec3b>(i);
        cv::Vec3b *rptr_dst = dst.ptr<cv::Vec3b>(i);
        // For each col (each pixel)
        for (int j = 0; j < src.cols; j++)
        {
            rptr_dst[j][0] = rptr_src[j][0] > bVal ? 0 : rptr_src[j][0];
            rptr_dst[j][1] = rptr_src[j][1] > gVal ? 0 : rptr_src[j][1];
            rptr_dst[j][2] = rptr_src[j][2] > rVal ? 0 : rptr_src[j][2];
        }
    }
    return 0;
}

// Extension: Control brightness using slider between 0 and 200%
// convert to HSV and change the V/intensity value only, then convert back to RGB
int adjustBrightness(cv::Mat &src, cv::Mat &dst, int brightness)
{
    cv::Mat hsvImage;
    cv::cvtColor(src, hsvImage, cv::COLOR_BGR2HSV); // Create hsvImage from src
    // For each row
    for (int i = 2; i < hsvImage.rows - 2; i++)
    {
        // set pointers
        cv::Vec3b *rptr_hsv = hsvImage.ptr<cv::Vec3b>(i);
        // For each col (each pixel)
        for (int j = 2; j < hsvImage.cols - 2; j++)
        {
            // Change the value/intensity channel
            int newBrightness = rptr_hsv[j][2] * brightness / 100;
            rptr_hsv[j][2] = newBrightness > 255 ? 255 : newBrightness;
        }
    }
    cv::cvtColor(hsvImage, dst, cv::COLOR_HSV2BGR); // Convert back to BGR
    return 0;
}

// Extension: Histogram equalization on Intensity (Value in HSV)
// Calculate a weighted cumulative histogram of intensity values and map to original intensity values
// Quantiles is the number of intensity quantiles to normalize the image intensity over
int histogramEqualization(cv::Mat &src, cv::Mat &dst, int quantiles)
{
    // 1. Convert image to HSV so we can adjust the intensity values
    cv::Mat hsvImg;
    cv::cvtColor(src, hsvImg, cv::COLOR_BGR2HSV);
    int pixelcount = 0;
    // 2. Create histogram of Intensity values
    int histogram[256] = {0}; // Each index represents an intensity value, each array value represents the frequency of the intensity value
    for (int i = 0; i < hsvImg.rows; i++)
    {
        // Get row pointer
        cv::Vec3b *rptr = hsvImg.ptr<cv::Vec3b>(i);
        for (int j = 0; j < hsvImg.cols; j++)
        {
            histogram[rptr[j][2]]++; // Find the index of intensity value and increment by 1
            pixelcount++;
        }
    }

    // 3. Calculate weighted histogram -> p of intensities in the image at each color channel
    double weightedHist[256] = {0.0};
    for (int x = 0; x < 256; x++)
    {
        weightedHist[x] = ((double)histogram[x] / (double)pixelcount);
    }

    // 4. Calculate cumulative weighted histogram -> array values represent cumulative probabiliy of intensity values 0-255
    double cumHistogram[256] = {0.0};
    double cum = 0.0;
    for (int x = 0; x < 256; x++)
    {
        cum += weightedHist[x];
        cumHistogram[x] = cum;
    }

    // 5. Get outputHist array
    int outputHist[256] = {0};
    for (int x = 0; x < 256; x++)
    {
        // outputHist[x] = (L - 1) * cumHistogram[x];
        outputHist[x] = ((quantiles - 1) * cumHistogram[x]) * 255 / quantiles;
    }

    // 6. Generate resulting image
    cv::Mat resultImg;
    hsvImg.convertTo(resultImg, CV_8UC3);
    for (int i = 0; i < hsvImg.rows; i++)
    {
        // get pointer
        cv::Vec3b *rptr_src = hsvImg.ptr<cv::Vec3b>(i);
        cv::Vec3b *rptr_dst = resultImg.ptr<cv::Vec3b>(i);
        for (int j = 0; j < hsvImg.cols; j++)
        {
            rptr_dst[j][2] = (uchar)outputHist[rptr_src[j][2]]; // output image intensity equals output hist intensity index value
        }
    }
    cv::cvtColor(resultImg, dst, cv::COLOR_HSV2BGR); // Convert color back to BGR for display

    return 0;
}