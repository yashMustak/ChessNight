#ifndef queen_header
#define queen_header

#include<iostream>

#include "prereq.hpp"

class Queen{
    public:
        Queen(bool isWhite);

        ~Queen();

        int getPriority() const;

        bool canMoveTo(Tile& toTile) const;

        void display();
};

#endif