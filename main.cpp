#include "opencv2/opencv.hpp"
#include <iostream>
#include "bright_vid.h"
#include "brightness.h"
#include "canny.h"
#include "resize.h"
#include "resize_vid.h"
#include "restruct.h"
#include "stitching.h"


using namespace std;
using namespace cv;

int main() {
	
	Light_dark_vid(char* video, double beta);
	//Light_dark(double beta, char* image);
	//Canny_edge(int threshold, char* image);
	//Resize(double scaleX, double scaleY, char* image);
	//Resize_vid(char* video, double scaleX, double scaleY);
	//Restruct(int size, char* image, int x);
	//Stitching(char* image_1, char* image_2);
	

	waitKey(0);

}