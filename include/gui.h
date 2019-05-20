#ifndef GUI_HEADER_CLASS
#define GUI_HEADER_CLASS

#include <string>
#include <iostream>

#include "imageEditor.h"
#include "mediaEditor.h"


enum FileType { Image, Video };

class CustomGui {

    private:
    const int WIN_HEIGHT = 870;
    const int WIN_WIDTH = 1000;
    const int MARGINS = 20;
    const int BLOCKS_HEIGHT = 150;

    const char* mediaWinName = "Editing image";
    const char* actionsWinName = "Choose an action to apply";
    const char* typeWinName = "Choose a media type";

    MediaEditor* editor;
    bool fileExists(const std::string&);
    bool openFileDialog(FileType);

    void chooseImageAction();

    public:
    CustomGui(MediaEditor* editor);
    void chooseFileLoop();

    void showEditingMedia();
    
    MediaEditor* getEditor() const;
    void setEditor(MediaEditor* editor);
    void chooseAction();
    

};

#endif