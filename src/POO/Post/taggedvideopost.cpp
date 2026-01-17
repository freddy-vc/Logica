#include "taggedvideopost.h"

TaggedVideoPost::TaggedVideoPost(std::string content, std::string mediaURL) : 
    VideoPost(content, mediaURL) {}

int TaggedVideoPost::getTipo() { return 7; }

void TaggedVideoPost::print(std::ostream& out) {
    Taggable::print(out);
    VideoPost::print(out);
}