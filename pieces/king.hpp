#ifndef King_header
#define King_header

#include <cstdlib>

#include "..\piece.hpp"

class King : public Piece
{
public:
    King(bool isWhite);

    bool moveTo(bool isWhite, Tile *toTile);

    bool canMoveTo(Tile *toTile);

    void symbol();

    bool hasMoved() const;

    int getPriority() const;

private:
    bool _moved;
    static const int _priority = 1;
};

#include "king_impl.hpp"

#endif