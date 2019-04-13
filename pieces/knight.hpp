#ifndef knight_header
#define knight_header

#include "prereq.hpp"

class Knight : public Piece{
    public:
        Knight(bool isWhite);

        ~Knight();

        int getPriority() const;

        bool canMoveTo(Tile& toTile) const;

        void display();
};

#include "knight_impl.hpp"

#endif