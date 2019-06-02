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

	
	
	void Light_dark_vid(char* video, double beta);

		char* video = new char[256];
		cout << "choose a video" << endl;
		cin >> video;
		double beta;
		cout << "choose your brightness factor" << endl;
		cin >> beta;
		Light_dark_vid(video, beta);
		return 0;

	

	//void Light_dark(double beta, char* image);

	//	char* image = new char[256];
	//	cout<<"choose an image"<<endl;
	//	cin>>image;
	//	double beta;
	//	cout<<"choose your brightness factor"<<endl;
	//	cin>>beta;
	//	Light_dark(beta,image);
	//	return 0;


	//void Canny_edge(int threshold, char* image);

	//	char* image = new char[256];
	//	int threshold;
	//	cout<<"choose an image"<<endl;
	//	cin>>image;
	//	cout<<"choose threshold"<<endl;
	//	cin>>threshold;
	//	Canny_edge(threshold,image);
	//	return 0;


	//void Resize(double scaleX, double scaleY, char* image);

	//	char* image = new char[256];
	//	double scaleX,scaleY;
	//	cout<<"choose an image"<<endl;
	//	cin>>image;
	//	cout<<"modify scaleX"<<endl;
	//	cin>>scaleX;
	//	cout<<"modify scaleY"<<endl;
	//	cin>>scaleY;
	//	Resize(scaleX,scaleY,image);
	//	return 0;

	//void Resize_vid(char* video, double scaleX, double scaleY);

	//  char* video = new char[256];
	//  double scaleX,scaleY;
	//  cout<<"choose a video"<<endl;
	//  cin>>video;
	//  cout<<"modify scaleX"<<endl;
	//  cin>>scaleX;
	//  cout<<"modify scaleY"<<endl;
	//  cin>>scaleY;
	//  Resize_vid(video,scaleX,scaleY);
	//  return 0;

	//void Restruct(int size, char* image, int x);

	//	int size,x;
	//	cout<<"choose if you want to erode(1) or dilate(2)"<<endl;
	//	cin>>x;
	//	cout<<"choose a size"<<endl;
	//	cin>>size;
	//	char* image = new char[256];
	//	cout<<"choose an image"<<endl;
	//	cin>>image;
	//	Restruct(size,image,x);
	//	return 0;

	//void Stitching(char* image_1, char* image_2);

	//    char* image_1 = new char[256];
	//    char* image_2 = new char[256];
	//    cout<<"choose an image"<<endl;
	//    cin>>image_1;
	//    cout<<"choose an image"<<endl;
	//    cin>>image_2;
	//    Stitching(image_1,image_2);
	//    return 0;


	//waitKey(0);

}