#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

void light_dark(double beta,char* image){
Mat source;
source = imread(image, IMREAD_COLOR);
/*if(!source.data )
    {
   printf( " No image data \n " );
   return -1;
    }*/
Mat new_image;
int y,x,c;
new_image=Mat::zeros(source.rows,source.cols,source.type());
//asking for alpha [1.0-3.0] and beta values [0-100]
    for( y=0; y<source.rows; y++ ) {
        for( x=0; x<source.cols; x++ ) {
            for( c=0; c<3; c++ ) {
                new_image.at<Vec3b>(y,x)[c] =
                  saturate_cast<uchar>(( source.at<Vec3b>(y,x)[c] ) + beta );
           }
        }
    }
    
     //create windows    
    namedWindow("Display new", WINDOW_AUTOSIZE);
    imshow("Display new",new_image);
    waitKey();   
}

int main(){
	char* image = new char[256];
  cout<<"choose an image"<<endl;
	cin>>image;
	double beta;
	cout<<"choose your brightness factor"<<endl;
	cin>>beta;
	light_dark(beta,image);
	return 0;
}