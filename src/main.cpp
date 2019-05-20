#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>


#include "gui.h"
#include "mediaEditor.h"
#include "imageEditor.h"

#define CVUI_IMPLEMENTATION
#include "cvui.h"

using namespace std;
using namespace cv;



int main(int argc, char const *argv[])
{
  
  MediaEditor* editor = new MediaEditor();


  CustomGui* gui = new CustomGui(editor);

  gui->chooseFileLoop();

  cout << "In main = " << gui->getEditor()->getFile();

  gui->showEditingMedia();

  
  gui->chooseAction();

  /* code */
  return 0;
}


