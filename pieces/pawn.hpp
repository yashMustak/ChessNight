#ifndef pawn_header
#define pawn_header

#include "prereq.hpp"

class Pawn : public Piece{
    public:
        Pawn(bool isWhite);

        ~Pawn();

        int getPriority() const;

        bool canMoveTo(Tile& toTile) const;

        void display();
};

// #include "pawn_impl.hpp"

#endif