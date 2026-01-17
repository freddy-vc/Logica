#ifndef TAGGEDTEXTPOST_H
#define TAGGEDTEXTPOST_H

#include "taggable.h"
#include "textpost.h"

class TaggedTextPost : public Taggable, public TextPost {
    protected:
        void print(std::ostream& out) override;
    public:
        TaggedTextPost(std::string content);

        int getTipo() override;
};

#endif