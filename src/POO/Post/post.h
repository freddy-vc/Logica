#ifndef POST_H
#define POST_H

#include "likeable.h"
#include "commentable.h"
#include <vector>

class Post : public Likeable, public Commentable {
    protected:
        std::string content;
        int likes;
        std::vector<std::string> comments;

        virtual void print(std::ostream& out) = 0;
    public:
        Post(std::string content);
        
        void like() override;
        void addComment(std::string comment) override;
        virtual int getTipo() = 0;
        void setContent(std::string c);
        friend std::ostream& operator<<(std::ostream& out, Post* p);
};

#endif