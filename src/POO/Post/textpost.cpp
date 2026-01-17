#include "textpost.h"

TextPost::TextPost(std::string content) : Post(content) {}

int TextPost::getTipo(){ return 1; }

void TextPost::print(std::ostream& out) {
    out << "Content:\t" << content << std::endl << "Likes:\t" << likes << std::endl
        << "Comments: " << std::endl;
    
    for(const std::string& c : comments) { out << "* " << c << std::endl; }
}