#include "taggedphotopost.h"

TaggedPhotoPost::TaggedPhotoPost(std::string content, std::string mediaURL) : 
    PhotoPost(content, mediaURL) {}

int TaggedPhotoPost::getTipo() { return 6; }

void TaggedPhotoPost::print(std::ostream& out) {
    Taggable::print(out);
    PhotoPost::print(out);
}