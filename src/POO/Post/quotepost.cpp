#include "quotepost.h"

QuotePost::QuotePost(std::string content, std::string quote) : TextPost(content), quote(quote) {}

int QuotePost::getTipo(){ return 2; }

void QuotePost::print(std::ostream& out) {
    out << "Content:\t" << content << std::endl << "Quote:\t" <<  quote << std::endl 
        << "Likes:\t" << likes << std::endl << "Comments: " << std::endl;
    
    for(const std::string& c : comments) { out << "* " << c << std::endl; }
}