//
//  main.cpp
//  compVision_1
//
//  Created by Michael Hart on 1/3/23.
//

#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

// **MAKE SURE YOU update these variables
std::string DIRECTORY = "/Users/michaelhart/Documents/Northeastern University/5330_ComputerVision/compVision_1/compVision_1/";
std::string IMAGE_TO_READ = "testImage.jpg"; // The filename of the image to read
std::string SAVENAME = "savedImage.jpg";     // The name you want the image saved as

int main(int argc, const char *argv[])
{
    Mat img = imread(DIRECTORY + IMAGE_TO_READ, IMREAD_COLOR);
    if (img.empty())
    {
        std::cout << "Could not read the image: " << IMAGE_TO_READ << std::endl;
        return 1;
    }
    imshow("Display window", img);
    while (true)
    {
        int k = waitKey(0); // Wait for a keystroke in the window

        if (k == 'Q' || k == 'q')
        {
            std::cout << "YOU PRESSED 'Q' -> EXITING\n";
            return 0;
        }
        else if (k == 's')
        {
            cv::imwrite(DIRECTORY + SAVENAME, img);
        }
    }
}
