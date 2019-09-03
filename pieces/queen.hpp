#ifndef Queen_header
#define Queen_header

#include <cstdlib>

#include "..\piece.hpp"

class Queen : public Piece
{
public:
    Queen(bool isWhite);

    bool canMoveTo(Tile *toTile);

    void symbol();

    int getPriority() const;

private:
    static const int _priority = 2;
};

#include "queen_impl.hpp"

#endif