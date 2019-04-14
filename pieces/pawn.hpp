#ifndef pawn_header
#define pawn_header

#include<ostream>

#if defined(__unix__)
#include "../restricted.hpp"
#include "../tile.hpp"

#elif defined(_WIN64)
#include "..\restricted.hpp"
#include "../tile.hpp"

#elif defined(__APPLE__)
#include "../restricted.hpp"
#include "../tile.hpp"
#endif

#include "queen.hpp"
#include "rook.hpp"
#include "bishop.hpp"
#include "knight.hpp"

class Pawn : public RestrictedPiece{
    public:
        Pawn(bool isWhite);

        ~Pawn();

        int getPriority() const;

        bool moveTo( Player& byPlayer, Tile& toTile );

        bool canMoveTo( Tile& toTile ) const;

        void display();

    private:
        Piece* _promotedTo;
};

#include "pawn_impl.hpp"

#endif