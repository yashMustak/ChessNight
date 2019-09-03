#ifndef Bishop_header
#define Bishop_header

#include <cstdlib>

#include "..\piece.hpp"

class Bishop : public Piece
{
public:
    Bishop(bool isWhite);

    bool canMoveTo(Tile *toTile);

    void symbol();

    int getPriority() const;

private:
    static const int _priority = 4;
};

#include "bishop_impl.hpp"

#endif