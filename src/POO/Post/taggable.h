#ifndef TAGGABLE_H
#define TAGGABLE_H

#include <iostream>
#include <vector>

class Taggable {
    protected:
        void print(std::ostream& out);
    public:
        std::vector<std::string> tags;
        void addTag(std::string tag);
};

#endif