#include "photopost.h"

PhotoPost::PhotoPost(std::string content, std::string mediaURL) : MediaPost(content, mediaURL) {}

int PhotoPost::getTipo(){ return 3; }

void PhotoPost::print(std::ostream& out) {
    out << "Content:\t" << content << std::endl << "Photo:\t" << mediaURL << std::endl << "Likes:\t" << likes << std::endl
        << "Comments: " << std::endl;
    
    for(const std::string& c : comments) { out << "* " << c << std::endl; }
}