#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

#include "mediaEditor.h"
#include "imageEditor.h"

using namespace std;
using namespace cv;


ImageEditor::ImageEditor() {

}

void ImageEditor::loadMedia() {
    this->baseMedia = imread(this->file);
    this->editingMedia = imread(this->file);
}

void ImageEditor::resize(double scaleX, double scaleY) {
    cv::resize(this->editingMedia, this->editingMedia, Size(), scaleX, scaleY, INTER_LINEAR);
}

void ImageEditor::brighten(int beta) {
    int y,x,c;
    // new_image=Mat::zeros(source.rows,source.cols,source.type());
    //asking for alpha [1.0-3.0] and beta values [0-100]
        for( y=0; y<this->editingMedia.rows; y++ ) {
            for( x=0; x<this->editingMedia.cols; x++ ) {
                for( c=0; c<3; c++ ) {
                    this->editingMedia.at<Vec3b>(y,x)[c] =
                    saturate_cast<uchar>(( this->editingMedia.at<Vec3b>(y,x)[c] ) + beta );
            }
            }
        }
}

void ImageEditor::cannyEdge(int threshold) {
    Mat temp;
    this->editingMedia.copyTo(temp);
    Canny(temp, this->editingMedia, threshold, threshold*3, 3);

}

void ImageEditor::restruct(int size, bool erode) {
    
	Mat element=getStructuringElement(MORPH_RECT,Size(2*size+1,2*size+1),Point(size,size));
	if (erode){
		cv::erode(this->editingMedia, this->editingMedia, element);
	}
	else {
		cv::dilate(this->editingMedia, this->editingMedia, element);
	}
}

// ImageEditor::~ImageEditor() {

// }

