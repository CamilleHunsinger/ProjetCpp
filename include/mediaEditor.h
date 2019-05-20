#ifndef MEDIA_EDITOR_CLASS
#define MEDIA_EDITOR_CLASS

#include <string>
#include <iostream>
#include <opencv2/opencv.hpp>

class MediaEditor {


    public:

    // enum Actions {};
    
    // typedef std::map<Actions, std::string> action_str_map;

    // action_str_map mapActToStr;

    virtual void loadMedia();

    std::string getFile() const;
    void setFile(const std::string& file);
    cv::Mat getBaseMedia() const;
    cv::Mat getEditingMedia() const;    
    virtual ~MediaEditor();


    protected:
    cv::Mat baseMedia;
    cv::Mat editingMedia;
    std::string file;
    
    
    

};

#endif