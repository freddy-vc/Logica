#include "post.h"

Post::Post(std::string content) : content(content), likes(0) {}
        
void Post::like(){ likes++; }

void Post::addComment(std::string comment){ comments.push_back(comment); }

void Post::setContent(std::string c) { content = c; }

std::ostream& operator<<(std::ostream& out, Post* p){
    p->print(out);

    return out;
}