#ifndef pawn_header
#define pawn_header

#include<iostream>

#include "prereq.hpp"

class Pawn{
    public:
        Pawn(bool isWhite);

        ~Pawn();

        int getPriority() const;

        bool canMoveTo(Tile& toTile) const;

        void display();
};

#endif