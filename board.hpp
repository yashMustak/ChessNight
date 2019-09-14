#ifndef board_header
#define board_header

#include "tile.hpp"
#include "piece.hpp"

class Board
{
public:
    Board();

    Tile *tileAt(int x, int y) const;

    bool isEmptyVertical(Tile *from, Tile *to) const;

    bool isEmptyHorizontal(Tile *from, Tile *to) const;

    bool isEmptyDiagonal(Tile *from, Tile *to) const;

    void display();

private:
    static const int _DIMENSION = 8;

    Tile *_tileArr[_DIMENSION][_DIMENSION];
};

#include "board_impl.hpp"

#endif
