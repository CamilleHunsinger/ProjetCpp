#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>


#include "gui.h"
#include "cvui.h"
#include "mediaEditor.h"
#include "imageEditor.h"


using namespace std;
using namespace cv;

CustomGui::CustomGui(MediaEditor* editor) {
    this->editor = editor;
}

bool CustomGui::fileExists(const std::string& filename) {
    std::ifstream ifile(filename.c_str());
    return (bool)ifile;
}

bool CustomGui::openFileDialog(FileType type) {


    char filename[200];

    FILE *f;

    if (type == FileType::Image) {
        f = popen("zenity --file-selection --file-filter=\"*.bmp *.dib *.jpg *.jpeg *.jpe *.jp2 *.png *.webp *.pbm *.pgm *.ppm *.sr *.ras *.tiff *tif\"", "r");
    }
    else if (type == FileType::Video) {
        f = popen("zenity --file-selection --file-filter=\"*.avi\"", "r");
    }

    fgets(filename, 200, f);


    std::string filename_string;

    filename_string = filename;

    filename_string.pop_back();

    if (!fileExists(filename_string)) {
        cout << "Doesn't exist:" << endl;
        filename_string = "";
        return false;
    }

    if (type == Image) {
        this->editor = new ImageEditor();
        this->editor->setFile(filename_string);

    }

    return true;


}




void CustomGui::chooseFileLoop() {

    const char* winName = this->typeWinName;
    cvui::init(winName);
    cv::Mat frame = cv::Mat(cv::Size(this->WIN_WIDTH, this->WIN_HEIGHT), CV_8UC3);

    bool fileChosen = false;

    while(!fileChosen) {

        frame = cv::Scalar(49, 52, 49);
        cvui::text(frame, 10, 15, "Hello world!");

        // Show window content
        if (cvui::button(frame, 300, 80, "Open an image")) {
            if (openFileDialog(Image)) {
                return;
            }
            // return FileType.Image;
        }
        else if (cvui::button(frame, 300, 40, "Open a video")) {
            if(openFileDialog(Video)){
                return;
            }
            // return FileType.Video;
        }

        cvui::imshow(winName, frame);


        if (cv::waitKey(20) == 27) {
            break;
        }
    
  }

}

MediaEditor* CustomGui::getEditor() const { 
    return this->editor;
}

void CustomGui::setEditor(MediaEditor* editor) {
    this->editor = editor;
}

void CustomGui::chooseImageAction() {

    const char* winName = this->actionsWinName;
    cvui::init(winName);
    cv::Mat frame = cv::Mat(cv::Size(this->WIN_WIDTH, this->WIN_HEIGHT), CV_8UC3);

    ImageEditor* ed = (ImageEditor*) (this->editor);

    double resizeScaleX= 1, resizeScaleY = 1;

    int brightnessBeta = 0;

    int cannyThreshold = 85;

    int restructSize;

   
    while(true) {

         int x= 0, y = 0, w = 0, h = 0, prevBlockEndsY = 0;


        frame = cv::Scalar(150, 150, 150);


        // ****** resize ***************************
        x += this->MARGINS;
        y = prevBlockEndsY + this-> MARGINS;
        prevBlockEndsY = y + this->BLOCKS_HEIGHT;
        w = this->WIN_WIDTH - (2 * this->MARGINS);
        h = this->BLOCKS_HEIGHT;
        cvui::window(frame, x, y, w, h, "Resize");
        x += this->MARGINS;
        y += 2*this-> MARGINS;
        w = 350;
        h = 20;
        cvui::text(frame,x, y, "Scale on x");
        x+= w + this->MARGINS;
        cvui::text(frame,x, y, "Scale on x");
        x = 2 * this->MARGINS;
        y += h + this->MARGINS;
        cvui::trackbar(frame, x, y, w, &resizeScaleX, (double)0.1, (double)3.0);
        x+= w + this->MARGINS;
        cvui::trackbar(frame, x, y, w, &resizeScaleY, (double)0.1, (double)3.0);
        x+= w + this->MARGINS;
        if (cvui::button(frame, x, y, "Resize")) {
            ed->resize(resizeScaleX, resizeScaleY);
            this->showEditingMedia();
        }
        // ***********************************************************


        // ****** brightnen/darken ***********************************
        x = this->MARGINS;
        y = prevBlockEndsY + this->MARGINS;
        prevBlockEndsY = y + this->BLOCKS_HEIGHT;
        w = this->WIN_WIDTH - (2 * this->MARGINS);
        h = this->BLOCKS_HEIGHT;
        cvui::window(frame, x, y, w, h, "Brightness");
        x += this->MARGINS;
        y += 2*this-> MARGINS;
        w = 700;
        h = 20;
        cvui::text(frame,x, y, "Beta");
        x = 2 * this->MARGINS;
        y += h + this->MARGINS;
        cvui::trackbar(frame, x, y, w, &brightnessBeta, (int)-255, (int)255);
        x += w + this->MARGINS;

        if (cvui::button(frame, x, y, "Brighten/Darken")) {
            ed->brighten(brightnessBeta);
            this->showEditingMedia();
        }
        // ***********************************************************

        // ****** canny edge ***********************************
        x = this->MARGINS;
        y = prevBlockEndsY + this->MARGINS;
        prevBlockEndsY = y + this->BLOCKS_HEIGHT;
        w = this->WIN_WIDTH - (2 * this->MARGINS);
        h = this->BLOCKS_HEIGHT;
        cvui::window(frame, x, y, w, h, "Canny edges detection");
        x += this->MARGINS;
        y += 2*this-> MARGINS;
        w = 700;
        h = 20;
        cvui::text(frame,x, y, "Lower threshold");
        x = 2 * this->MARGINS;
        y += h + this->MARGINS;
        cvui::trackbar(frame, x, y, w, &cannyThreshold, (int)-0, (int)200);
        x += w + this->MARGINS;

        if (cvui::button(frame, x, y, "Detect edges")) {
            ed->cannyEdge(cannyThreshold);
            this->showEditingMedia();
        }
        // ***********************************************************

        // ****** restruct (erode / dilate)**************************
        x = this->MARGINS;
        y = prevBlockEndsY + this->MARGINS;
        prevBlockEndsY = y + this->BLOCKS_HEIGHT;
        w = this->WIN_WIDTH - (2 * this->MARGINS);
        h = this->BLOCKS_HEIGHT;
        cvui::window(frame, x, y, w, h, "Restruct");
        x += this->MARGINS;
        y += 2*this-> MARGINS;
        w = 700;
        h = 20;
        cvui::text(frame,x, y, "Size");
        x = 2 * this->MARGINS;
        y += h + this->MARGINS;
        cvui::trackbar(frame, x, y, w, &restructSize, (int)1, (int)50);
        x += w + this->MARGINS;
        if (cvui::button(frame, x, y, "Erode")) {
            ed->restruct(restructSize, true);
            this->showEditingMedia();
        }
        x += 80;
        if (cvui::button(frame, x, y, "Dilate")) {
            ed->restruct(restructSize, false);
            this->showEditingMedia();
        }
        // ***********************************************************

        // ****** restruct (panorama)**************************
        x = this->MARGINS;
        y = prevBlockEndsY + this->MARGINS;
        prevBlockEndsY += this->BLOCKS_HEIGHT;
        w = this->WIN_WIDTH - (2 * this->MARGINS);
        h = this->BLOCKS_HEIGHT;
        cvui::window(frame, x, y, w, h, "Panorama");
        x += this->MARGINS;
        y += 2*this-> MARGINS;
        w = 700;
        h = 20;
        x = 2 * this->MARGINS;
        y += h + this->MARGINS;
        if (cvui::button(frame,x, y, "Open an image ...")) {
            // open file dialog
        }
        x += w + this->MARGINS;
        if (cvui::button(frame, x, y, "Make a panorama")) {
            // func
        }
        // ***********************************************************

        cvui::imshow(winName, frame);


        if (cv::waitKey(20) == 27) {
            break;
        }
    
  }

}

void CustomGui::chooseAction() {


    // remplacer par if type==ImageEditor
    if (true) {
        chooseImageAction();
    }

}

void CustomGui::showEditingMedia() {
    const char* winName = this->mediaWinName;
    //cvui::init(winName);
    //to try = 
    //cvui::image(frame, 10, 10, lena_face);
    imshow(winName, this->editor->getEditingMedia());
}