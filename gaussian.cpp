#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main_gaussian()
{
      // Read the image file
    Mat img = imread("van_gogh.jpg");
    Mat blurx3, blurx5;

    // Check for failure
    if (img.empty()) {
        cerr << "Can't read the image" << endl;
        return -1;
    }

    //Blur the image with 3x3 kernel
    GaussianBlur(img, blurx3, cv::Size(3, 3), 1, 1);

    //Blur the image with 5x5 kernel
    GaussianBlur(img, blurx5, cv::Size(5, 5), 1, 1);
    
    namedWindow("Gaussianx3", WINDOW_AUTOSIZE);
    namedWindow("Gaussianx5", WINDOW_AUTOSIZE);

    // Show our images inside the created windows.
    imshow("Gaussianx3", blurx3);
    imshow("Gaussianx5", blurx5);

    // Wait for any keystroke in the window
    cv::waitKey(0);

    destroyAllWindows();

    return 0;

    
}