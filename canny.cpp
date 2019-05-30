#include <opencv2/opencv.hpp>
#include <iostream>
#include "canny.h"

using namespace std;
using namespace cv;

void Canny_edge(int threshold,char* image){
	Mat source,dest;
	source = imread(image, IMREAD_COLOR);
	if(!source.data )
    {
   printf( " No image data \n " );
    }
	Canny(source,dest,threshold,threshold*3,3);
	namedWindow("Display Canny image", WINDOW_AUTOSIZE);
	imshow("Display Canny image",dest);
	waitKey(0);
}

int main(){
	char* image = new char[256];
	int threshold;
	cout<<"choose an image"<<endl;
	cin>>image;
	cout<<"choose threshold"<<endl;
	cin>>threshold;
	Canny_edge(threshold,image);
	return 0;
}