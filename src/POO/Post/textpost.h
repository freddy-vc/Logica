#ifndef TEXTPOST_H
#define TEXTPOST_H

#include "post.h"

class TextPost : public Post {
    protected:
        void print(std::ostream& out) override;
    public:
        TextPost(std::string content);
        int getTipo() override;
};


#endif