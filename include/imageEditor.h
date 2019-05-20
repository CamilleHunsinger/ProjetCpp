#ifndef IMAGE_EDITOR_CLASS
#define IMAGE_EDITOR_CLASS

#include <string>
#include <iostream>
#include "mediaEditor.h"


class ImageEditor : public MediaEditor {


    public:

    ImageEditor();

    void loadMedia();

    void resize(double scaleX, double scaleY);
    void brighten (int beta);
    void cannyEdge(int threshold);
    void restruct(int size, bool erode);
    



};

#endif