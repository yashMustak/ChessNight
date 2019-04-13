#ifndef rook_header
#define rook_header

#include<iostream>

#include "prereq.hpp"

class Rook{
    public:
        Rook(bool isWhite);

        ~Rook();

        int getPriority() const;

        bool canMoveTo(Tile& toTile) const;

        void display();
};

#endif