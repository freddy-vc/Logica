#ifndef PHOTOPOST_H
#define PHOTOPOST_H

#include "mediapost.h"

class PhotoPost : public MediaPost {
    protected:
        void print(std::ostream& out) override;
    public: 
        PhotoPost(std::string content, std::string mediaURL);
        int getTipo() override;
};


#endif