#include <opencv2/opencv.hpp>
#include <iostream>
#include "stitching.h"

// CPP program to Stitch 
// input images (panorama) using OpenCV  

#include <fstream> 

// Include header files from OpenCV directory 
// required to stitch images. 
#include "opencv2/imgcodecs.hpp" 
#include "opencv2/highgui.hpp" 
#include "opencv2/stitching.hpp" 

using namespace std;
using namespace cv;

// Define mode for stitching as panoroma  
// (One out of many functions of Stitcher) 
Stitcher::Mode mode = Stitcher::PANORAMA;

// Array for pictures 
vector<Mat> imgs;

void Stitching(char* image_1, char* image_2)
{
	// Read the ith argument or image  
	// and push into the image array 
	Mat img1 = imread(image_1);
	/*if (img1.empty())
	{
		// Exit if image is not present
		cout << "Can't read image '" << img1 << "'\n";
		return -1;
	}*/
	imgs.push_back(img1);

	Mat img2 = imread(image_2);
	/*if (img2.empty())
	{
		// Exit if image is not present
		cout << "Can't read image '" << img2 << "'\n";
		return -1;
	}*/
	imgs.push_back(img2);


	// Define object to store the stitched image 
	Mat pano;

	// Create a Stitcher class object with mode panoroma 
	
	Ptr<Stitcher> stitcher = Stitcher::create(mode);

	// Command to stitch all the images present in the image array 
	Stitcher::Status status = stitcher->stitch(imgs, pano);

	if (status != Stitcher::OK)
	{
		// Check if images could not be stiched 
		// status is OK if images are stiched successfully 
		cout << "Can't stitch images\n";

	}

	// Store a new image stiched from the given  
	//set of images as "result.jpg" 
	imwrite("result.jpg", pano);

	// Show the result 
	imshow("Result", pano);

	waitKey(0);
}
//int main(){
//    char* image_1 = new char[256];
//    char* image_2 = new char[256];
//    cout<<"choose an image"<<endl;
//    cin>>image_1;
//    cout<<"choose an image"<<endl;
//    cin>>image_2;
//    Stitching(image_1,image_2);
//    return 0;
//}