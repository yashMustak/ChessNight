#ifndef knight_header
#define knight_header

#include<iostream>

#include "prereq.hpp"

class Knight{
    public:
        Knight(bool isWhite);

        ~Knight();

        int getPriority() const;

        bool canMoveTo(Tile& toTile) const;

        void display();
};

#endif