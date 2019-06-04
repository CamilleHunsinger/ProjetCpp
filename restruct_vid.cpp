#include <opencv2/opencv.hpp>
#include <iostream>
#include "restruct_vid.h"

using namespace cv;
using namespace std;

void Restruct_vid(int size, char* video, int x)
{

	//open the video file for reading
	VideoCapture cap(video);
	// if not success, exit program
	if (!cap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
	}


	//imshow("new video",frame);
	while (true)
	{
		Mat frame;
		// read a new frame from video
		cap >> frame;

		//Breaking the while loop at the end of the video
		if (frame.data == 0)
			break;

		//Restruct function

		//Mat frame;
		Mat dest;
		Mat element = getStructuringElement(MORPH_RECT, Size(2 * size + 1, 2 * size + 1), Point(size, size));

		if (x == 1) {
			erode(frame, dest, element);
			namedWindow("Display eroded video", WINDOW_AUTOSIZE);
			imshow("Display eroded video", dest);
			//waitKey(0);
		}
		else if (x == 2) {
			dilate(frame, dest, element);
			namedWindow("Display dilated video", WINDOW_AUTOSIZE);
			imshow("Display dilated video", dest);
			//waitKey(0);
		}
		else {
			cout << "please relaunch and type in 1 or 2" << endl;

			
		}

		//wait for for 10 ms until any key is pressed.
		waitKey(10);
		//If the 'Esc' key is pressed, break the while loop.
		char c = (char)waitKey(25);
		if (c == 27)
			break;
		//If the any other key is pressed, continue the loop
		//If any key is not pressed withing 10 ms, continue the loop
		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Stoppig the video" << endl;
			break;
		}
	}

}