#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

void restruct(int size,char* image,int x){
	Mat source,dest;
	source = imread(image, IMREAD_COLOR);
	/*if(!source.data )
    {
   printf( " No image data \n " );
   return -1;
    }*/
	Mat element=getStructuringElement(MORPH_RECT,Size(2*size+1,2*size+1),Point(size,size));
	if (x==1){
		erode(source,dest,element);
		namedWindow("Display erdoded image", WINDOW_AUTOSIZE);
		imshow("Display eroded image",dest);
		waitKey(0);
	}
	else if (x==2){
		dilate(source,dest,element);
		namedWindow("Display dilated image", WINDOW_AUTOSIZE);
		imshow("Display dilated image",dest);
		waitKey(0);
	}
	else {
		cout<<"please relaunch and type in 1 or 2"<<endl;
	}
}
int main(){
	int size,x;
	cout<<"choose if you want to erode(1) or dilate(2)"<<endl;
	cin>>x;
	cout<<"choose a size"<<endl;
	cin>>size;
	char* image = new char[256];
	cout<<"choose an image"<<endl;
	cin>>image;
	restruct(size,image,x);
	return 0;
}