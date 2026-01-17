#include "mediapost.h"

MediaPost::MediaPost(std::string content, std::string mediaURL) : Post(content), mediaURL(mediaURL) {}

void MediaPost::setMediaURL(std::string url) { mediaURL = url; }