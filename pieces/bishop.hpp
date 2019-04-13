#ifndef bishop_header
#define bishop_header

#include "prereq.hpp"

class Bishop : public Piece{
    public:
        Bishop(bool isWhite);

        ~Bishop();

        int getPriority() const;

        bool canMoveTo(Tile& toTile) const;

        void display();
};

#include "bishop_impl.hpp"

#endif