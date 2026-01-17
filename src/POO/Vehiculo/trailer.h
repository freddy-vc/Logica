#ifndef TRAILER_H
#define TRAILER_H

#include <iostream>

class Trailer {
    private:
        float capacidad;
    protected:
    virtual void print(std::ostream& out) const;
    public:
        Trailer();
        Trailer(float capacidad);
        virtual ~Trailer() = default;

        float getCapacidad() const;
        
        void setCapacidad(float capacidad);
};


#endif