#ifndef Tile_header
#define Tile_header

#include <iostream>

class Piece;
class Board;

class Tile
{
public:
    Tile(int x, int y, Board *inBoard);

    void setPiece(Piece *piece);

    bool isEmpty();

    Piece *getPiece() const;

    Board *getBoard() const;

    int getX() const;

    int getY() const;

private:
    int _x, _y;
    Piece *_piece;
    Board *_inBoard;
};

#include "tile_impl.hpp"

#endif