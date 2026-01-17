#ifndef TAGGEDPHOTOPOST_H
#define TAGGEDPHOTOPOST_H

#include "taggable.h"
#include "photopost.h"

class TaggedPhotoPost : public Taggable, public PhotoPost {
    protected:
        void print(std::ostream& out) override;
    public:
        TaggedPhotoPost(std::string content, std::string mediaURL);
        int getTipo() override;
};

#endif