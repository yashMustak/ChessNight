#ifndef Player_header
#define Player_header

#include <string>
#include <set>

#include "piece.hpp"
#include ".\pieces\king.hpp"
#include "board.hpp"

class Player
{
public:
    Player(std::string name, bool isWhite);

    bool makeMove(Board *thisBoard);

    bool inCheck();

    bool isValidMove(Piece *thistPiece, Tile *toTile);

    void changeName(std::string newName);

    void setOppositePieces(set<Piece *> *oppositePiece);

    bool getColor() const;

    King *getKing() const;

    set<Piece *> getPieceSet() const;

    std::string getName() const;

    set<Piece *> *getOppositePieces() const;

    std::set<Piece *> getPeices() const;

    std::set<Piece *> getCaptured() const;

private:
    King *_myKing;
    std::string _name;
    bool _isWhite;
    set<Piece *> *_oppositePieces;
    std::set<Piece *> _myPieces;
    std::set<Piece *> _capturedPieces;
};

#include "player_impl.hpp"

#endif