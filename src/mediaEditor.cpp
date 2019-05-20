#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

#include "mediaEditor.h"

using namespace std;
using namespace cv;


void MediaEditor::setFile(const string& file) {
    this->file = file;
    this->loadMedia();
}

string MediaEditor::getFile() const{
    cout << "File is " << this->file << endl;
    return this->file;
}

cv::Mat MediaEditor::getBaseMedia() const{
    return this->baseMedia;
}

cv::Mat MediaEditor::getEditingMedia() const {
    return this->editingMedia;
}

void MediaEditor::loadMedia() {
    
}

MediaEditor::~MediaEditor(){

}