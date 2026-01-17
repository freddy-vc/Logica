#include "videopost.h"

VideoPost::VideoPost(std::string content, std::string mediaURL) : MediaPost(content, mediaURL) {}

int VideoPost::getTipo(){ return 4; }

void VideoPost::print(std::ostream& out) {
    out << "Content:\t" << content << std::endl << "Video:\t" << mediaURL << std::endl << "Likes:\t" << likes << std::endl
        << "Comments: " << std::endl;
    
    for(const std::string& c : comments) { out << "* " << c << std::endl; }
}