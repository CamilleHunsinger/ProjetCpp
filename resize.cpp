#include <opencv2/opencv.hpp>
#include "resize.h"

using namespace std;
using namespace cv;

// Scaling down the image 0.6 times
	void Resize(double scaleX,double scaleY,char* image){
Mat source, dest;
// Read source image
source = imread(image, IMREAD_COLOR);
if(!source.data )
    {
   printf( " No image data \n " );
    }
resize(source,dest,Size(),scaleX,scaleY,INTER_LINEAR);
namedWindow("Display resized image", WINDOW_AUTOSIZE);
imshow("Display resized image",dest);
waitKey(0);
}

int main(){
	char* image = new char[256];
	double scaleX,scaleY;
	cout<<"choose an image"<<endl;
	cin>>image;
	cout<<"modify scaleX"<<endl;
	cin>>scaleX;
	cout<<"modify scaleY"<<endl;
	cin>>scaleY;
	Resize(scaleX,scaleY,image);
	return 0;
}