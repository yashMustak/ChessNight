#ifndef restricted_header
#define restricted_header

#include "piece.hpp"

class RestrictedPiece : public Piece{
    
    public:
        RestrictedPiece(bool isWhite);

        virtual ~RestrictedPiece();

        virtual bool moveTo( Player& byPlayer, Tile& toTile );

        bool hasMoved() const;

    private:

        bool _moved;
};

#include "restricted_impl.hpp"

#endif