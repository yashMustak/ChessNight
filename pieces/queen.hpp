#ifndef queen_header
#define queen_heade

#include "prereq.hpp"

class Queen : public Piece{
    public:
        Queen(bool isWhite);

        ~Queen();

        int getPriority() const;

        bool canMoveTo(Tile& toTile) const;

        void symbol();
};

#include "queen_impl.hpp"

#endif
