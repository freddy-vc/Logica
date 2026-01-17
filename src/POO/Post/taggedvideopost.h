#ifndef TAGGEDVIDEOPOST_H
#define TAGGEDVIDEOPOST_H

#include "taggable.h"
#include "videopost.h"

class TaggedVideoPost : public Taggable, public VideoPost {
    protected:
        void print(std::ostream& out) override;
    public:
        TaggedVideoPost(std::string content, std::string mediaURL);
        int getTipo() override;
};

#endif