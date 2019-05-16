#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void Light_dark_vid(char* video,double beta)
{
    double alpha = 1;
    //open the video file for reading
    VideoCapture cap(video);
    // if not success, exit program
  if(!cap.isOpened()){
    cout << "Error opening video stream or file" << endl;
  }

    //Defining window names
  namedWindow("Display video", WINDOW_AUTOSIZE);
    //Create and open windows for above window names
    
    //imshow("new video",frame);
    while (true)
    {
        Mat frame;
    // read a new frame from video
        cap >> frame;
    
    //Breaking the while loop at the end of the video
     if(frame.data==0)
      break;                 
Mat video1;
        //increase the brightness by 50
frame.convertTo(video1,frame.type(),alpha,beta) ;
        //Show above frames inside the created windows.
imshow("Display video",video1);


        //wait for for 10 ms until any key is pressed.
waitKey(10);
        //If the 'Esc' key is pressed, break the while loop.
char c=(char)waitKey(25);
    if(c==27)
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

int main(){
  char* video = new char[256];
  cout<<"choose a video"<<endl;
  cin>>video;
  double beta;
  cout<<"choose your brightness factor"<<endl;
  cin>>beta;
  Light_dark_vid(video,beta);
  return 0;
}