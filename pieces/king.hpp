#ifndef king_header
#define king_header

#include<iostream>

#include "prereq.hpp"

class King{
    public:
        King(bool isWhite);

        ~King();

        int getPriority() const;

        bool canMoveTo(Tile& toTile) const;

        void display();
};

#endif