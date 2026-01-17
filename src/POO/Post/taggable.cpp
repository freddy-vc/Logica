#include "taggable.h"

void Taggable::addTag(std::string tag) { tags.push_back(tag); }

void Taggable::print(std::ostream& out) {
    out << "Tags: " << std::endl; 
    for(const std::string& t : tags) { 
        out << "#" << t << std::endl;
    }
}