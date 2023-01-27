//
//  main.cpp
//  vidDisplay
//
//  Created by Michael Hart on 1/13/23.
//
#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "vidDisplay.h"

using namespace cv;

// !!! CHANGE THIS VARIABLE TO THE LOCATION YOU WANT TO SAVE THE IMAGES WHEN THE USER PRESSES THE 's' KEY
std::string SAVEPATH = "/Users/michaelhart/Documents/Northeastern University/5330_ComputerVision/project1/vidDisplay/";

// Main
int main(int argc, char *argv[])
{
        cv::VideoCapture *capdev;

        // open the video device
        capdev = new cv::VideoCapture(0);
        if (!capdev->isOpened())
        {
                printf("Unable to open video device\n");
                return (-1);
        }

        // get some properties of the image
        cv::Size refS((int)capdev->get(cv::CAP_PROP_FRAME_WIDTH),
                      (int)capdev->get(cv::CAP_PROP_FRAME_HEIGHT));
        printf("Expected size: %d %d\n", refS.width, refS.height);

        cv::Mat frame;         // declare the frame
        String mode = "color"; // Default filter mode is "color"

        cv::namedWindow("Video", 1);                     // identifies a window
        int bSlider = 255, gSlider = 255, rSlider = 255; // default values for the color threshold filter
        int brightSlider = 100;                          // default value for adjust brightness mode

        for (;;)
        {
                *capdev >> frame;              // get a new frame from the camera, treat as a stream
                int bVal = bSlider;            // set blue value to the slider value (used on color threshold filter)
                int gVal = gSlider;            // set green value to the slider value (used on color threshold filter)
                int rVal = rSlider;            // set red value to the slider value (used on color threshold filter)
                int brightness = brightSlider; // set brightness value to the slider value (used on adjust brightness filter)
                if (frame.empty())
                {
                        printf("frame is empty\n");
                        break;
                }

                // Handle filter modes
                if (mode == "grayscale")
                {
                        int w = mainGrayscale(&frame, &frame);
                }
                else if (mode == "altGray")
                {
                        int w = greyscale(frame, frame);
                }
                else if (mode == "blur")
                {
                        int w = blur5x5(frame, frame);
                        // cv::GaussianBlur(frame, frame, Size(5, 5), 1); // Placeholder for testing
                }
                else if (mode == "sobelX")
                {
                        int w = sobelX3x3(frame, frame); // Output frame is CV_16S
                        frame.convertTo(frame, CV_8U);   // convert CV_16S to CV_8U type to display
                }
                else if (mode == "sobelY")
                {
                        int w = sobelY3x3(frame, frame); // Output frame is CV_16S
                        frame.convertTo(frame, CV_8U);   // convert CV_16S to 8U type to display
                }
                else if (mode == "magnitude")
                {
                        cv::Mat sx, sy;
                        int w = sobelX3x3(frame, sx);
                        int y = sobelY3x3(frame, sy);
                        int z = magnitude(sx, sy, frame);
                }
                else if (mode == "quantize")
                {
                        int s = blurQuantize(frame, frame, 15);
                }
                else if (mode == "cartoon")
                {
                        int s = cartoon(frame, frame, 8, 25);
                }
                else if (mode == "negative")
                {
                        int s = negative(frame, frame);
                }
                else if (mode == "smooth")
                {
                        int s = smooth5x5(frame, frame);
                }
                else if (mode == "colorThresholds")
                {
                        int s = colorMinimums(frame, frame, bVal, gVal, rVal);
                }
                else if (mode == "brightness")
                {
                        int s = adjustBrightness(frame, frame, brightness);
                }
                else if (mode == "histEqualization")
                {
                        int s = histogramEqualization(frame, frame, 200);
                }

                cv::imshow("Video", frame); // Show the video
                // see if there is a waiting keystroke
                char key = cv::waitKey(10);
                switch (key)
                {
                case 'q': // QUIT
                        return 0;
                case 's': // Save an image
                        std::cout << "Saving " << mode << " Image" << std::endl;
                        cv::imwrite(SAVEPATH + "savedImage_" + mode + ".jpg", frame);
                        break;
                case 'g':
                        toggleFilterMode(&mode, "grayscale");
                        break;
                case 'h':
                        toggleFilterMode(&mode, "altGray");
                        break;
                case 'b':
                        toggleFilterMode(&mode, "blur");
                        break;
                case 'x':
                        toggleFilterMode(&mode, "sobelX");
                        break;
                case 'y':
                        toggleFilterMode(&mode, "sobelY");
                        break;
                case 'm':
                        toggleFilterMode(&mode, "magnitude");
                        break;
                case 'l':
                        toggleFilterMode(&mode, "quantize");
                        break;
                case 'c':
                        toggleFilterMode(&mode, "cartoon");
                        break;
                case 'n':
                        toggleFilterMode(&mode, "negative");
                        break;
                case 't':
                        toggleFilterMode(&mode, "smooth");
                        break;
                case 'e':
                        toggleFilterMode(&mode, "histEqualization");
                        break;
                case 'z':
                        toggleFilterMode(&mode, "colorThresholds");
                        cv::namedWindow("colorSliders", 1); // identifies a window
                        cv::createTrackbar("Blue", "colorSliders", &bSlider, 180, NULL);
                        cv::createTrackbar("Green", "colorSliders", &gSlider, 255, NULL);
                        cv::createTrackbar("Red", "colorSliders", &rSlider, 255, NULL);
                        cv::imshow("colorSliders", NULL);
                        break;
                case 'a':
                        toggleFilterMode(&mode, "brightness");
                        cv::namedWindow("brightness", 1); // identifies a window
                        cv::createTrackbar("Brightness", "brightness", &brightSlider, 200, NULL);
                        cv::imshow("brightness", NULL);
                        break;
                }
                if (mode != "colorThresholds") // Destroy the trackpad window if user toggles out of colorThreshold mode
                {
                        cv::destroyWindow("colorSliders");
                }
                if (mode != "brightness") // Destroy the trackpad window if user toggles out of colorThreshold mode
                {
                        cv::destroyWindow("brightness");
                }
        }

        delete capdev;
        return (0);
}
