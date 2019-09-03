#ifndef Knight_header
#define Knight_header

#include <cstdlib>

#include "..\piece.hpp"

class Knight : public Piece
{
public:
    Knight(bool isWhite);

    bool canMoveTo(Tile *toTile);

    void symbol();

    int getPriority() const;

private:
    static const int _priority = 4;
};

#include "knight_impl.hpp"

#endif