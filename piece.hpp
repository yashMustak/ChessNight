#ifndef Piece_header
#define Piece_header

#include "tile.hpp"

#if defined(_WIN64)
#include <windows.h>
#endif

class Piece
{
public:
    Piece(bool isWhite);

    virtual bool moveTo(bool isWhite, Tile *toTile);

    virtual bool canMoveTo(Tile *toTile) = 0;

    virtual void symbol() = 0;

    virtual int getPriority() const = 0;

    void setPosition(Tile *tile);

    Tile *getPosition() const;

    bool getColor() const;

protected:
    bool _isWhite;
    Tile *_currentTile;
};

#include "piece_impl.hpp"

#endif