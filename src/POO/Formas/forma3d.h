#ifndef FORMA3D_H
#define FORMA3D_H

class Forma3D {
    public:
        virtual float getSuperficie() const = 0;
        virtual float getVolumen() const = 0;
};

#endif