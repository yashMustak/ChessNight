#ifndef pawn_header
#define pawn_header

#include<ostream>

#include "prereq.hpp"

#include "queen.hpp"
#include "rook.hpp"
#include "bishop.hpp"
#include "knight.hpp"

#if defined(__unix__)
#include "../player.hpp"

#elif defined(_WIN64)
#include "..\player.hpp"

#elif defined(__APPLE__)
#include "../player.hpp"
#endif

class Pawn : public Piece{
    public:
        Pawn(bool isWhite);

        ~Pawn();

        int getPriority() const;

        bool moveTo( Player& byPlayer, Tile& toTile );

        bool canMoveTo( Tile& toTile ) const;
        
        bool hasMoved() const;

        void symbol();

    private:
    	
        Piece* _promotedTo;
        
        bool _moved;
};

#include "pawn_impl.hpp"

#endif
