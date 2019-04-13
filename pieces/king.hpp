#ifndef king_header
#define king_header

#include "prereq.hpp"

class King : public RestrictedPiece{
    public:
        King(bool isWhite);

        ~King();

        int getPriority() const;

        bool canMoveTo(Tile& toTile) const;

        void display();
};

// #include "king_impl.hpp"

#endif