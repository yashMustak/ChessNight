#ifndef king_header
#define king_header

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

class King : public RestrictedPiece{
    public:
        King(bool isWhite);

        ~King();

        int getPriority() const;

        bool canMoveTo(Tile& toTile) const;

        void display();
};

#include "king_impl.hpp"

#endif