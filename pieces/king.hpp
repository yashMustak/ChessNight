#ifndef king_header
#define king_header

#include<ostream>

#include "prereq.hpp"

#if defined(__unix__)
#include "../player.hpp"

#elif defined(_WIN64)
#include "..\player.hpp"

#elif defined(__APPLE__)
#include "../player.hpp"
#endif

class King : public Piece{
    public:
        King(bool isWhite);

        ~King();

        int getPriority() const;
        
        bool moveTo( Player& byPlayer, Tile& toTile );

        bool canMoveTo(Tile& toTile) const;
        
        bool hasMoved() const;

        void symbol();
        
    private:
    	
    	bool _moved;
};

#include "king_impl.hpp"

#endif
