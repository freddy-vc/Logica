#include "taggedtextpost.h"

TaggedTextPost::TaggedTextPost(std::string content) : TextPost(content) {}

int TaggedTextPost::getTipo() { return 5; }

void TaggedTextPost::print(std::ostream& out) {
    Taggable::print(out);
    TextPost::print(out);
}