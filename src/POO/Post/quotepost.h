#ifndef QUOTEPOST_H
#define QUOTEPOST_H

#include "textpost.h"

class QuotePost : public TextPost {
    protected:
        void print(std::ostream& out) override;
    public:
        std::string quote;

        QuotePost(std::string content, std::string quote);
        int getTipo() override;
};


#endif