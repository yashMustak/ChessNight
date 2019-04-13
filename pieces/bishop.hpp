#ifndef bishop_header
#define bishop_header

#include<iostream>

#include "prereq.hpp"

class Bishop{
    public:
        Bishop(bool isWhite);

        ~Bishop();

        int getPriority() const;

        bool canMoveTo(Tile& toTile) const;

        void display();
};

#endif