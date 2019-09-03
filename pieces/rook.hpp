#ifndef Rook_header
#define Rook_header

#include <cstdlib>

#include "..\piece.hpp"

class Rook : public Piece
{
public:
    Rook(bool isWhite);

    bool canMoveTo(Tile *toTile);

    void symbol();

    int getPriority() const;

private:
    static const int _priority = 3;
};

#include "rook_impl.hpp"

#endif