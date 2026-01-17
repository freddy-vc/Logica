#ifndef COMMENTABLE_H
#define COMMENTABLE_H

#include <iostream>

class Commentable {
    public:
    virtual void addComment(std::string comment) = 0;
};

#endif