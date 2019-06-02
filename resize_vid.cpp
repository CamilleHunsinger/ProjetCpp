#include <opencv2/opencv.hpp>
#include <iostream>
#include "resize_vid.h"

using namespace std;
using namespace cv;

void Resize_vid(char* video, double scaleX, double scaleY) {

	// Create a VideoCapture object and open the input file
	// If the input is the web camera, pass 0 instead of the video file name VideoCapture cap(0);
	VideoCapture cap(video);
	// Check if camera opened successfully
	if (!cap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
	}

	while (1) {

		Mat frame;
		// Capture frame-by-frame
		cap >> frame;

		// If the frame is empty, break immediately
		if (frame.data == 0)
			break;
		Mat resized;
		resize(frame, resized, Size(), scaleX, scaleY, INTER_LINEAR);

		// Display the resulting frame
		imshow("video", resized);
		waitKey(1);
		// Press  ESC on keyboard to exit
		char c = (char)waitKey(25);
		if (c == 27)
			break;
	}

	// When everything done, release the video capture object
	cap.release();

	// Closes all the frames
	destroyAllWindows();

}

//int main(){
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
//}
