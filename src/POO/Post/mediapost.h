#ifndef MEDIAPOST_H
#define MEDIAPOST_H

#include "post.h"

class MediaPost : public Post {
    protected:
        std::string mediaURL;
    public:
        MediaPost(std::string content, std::string mediaURL);
        void setMediaURL(std::string url);
};

#endif