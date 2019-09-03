#ifndef Pawn_header
#define Pawn_header

#include <cstdlib>

#include "..\piece.hpp"
#include "queen.hpp"
#include "rook.hpp"
#include "bishop.hpp"
#include "knight.hpp"

class Pawn : public Piece
{
public:
    Pawn(bool isWhite);

    bool moveTo(bool isWhite, Tile *toTile);

    bool canMoveTo(Tile *toTile);

    void symbol();

    bool hasMoved() const;

    int getPriority() const;

private:
    bool _moved;
    static const int _priority = 5;
};

#include "pawn_impl.hpp"

#endif