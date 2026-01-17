#ifndef VIDEOPOST_H
#define VIDEOPOST_H

#include "mediapost.h"

class VideoPost : public MediaPost {
 protected:
        void print(std::ostream& out) override;
    public: 
        VideoPost(std::string content, std::string mediaURL);
        int getTipo() override;
};

#endif