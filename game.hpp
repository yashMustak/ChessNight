#ifndef Game_header
#define Game_header

#include "player.hpp"

#include "pieces\queen.hpp"
#include "pieces\bishop.hpp"
#include "pieces\rook.hpp"
#include "pieces\knight.hpp"
#include "pieces\pawn.hpp"

class Game
{
public:
    Game();

    void initialize();

    Board *getBoard();

    Player *opponentOf(Player *thisPlayer);

    void setCurrentPlayer(Player *thisPlayer);

    void setPlayerWon(Player *playerWon);

    Player *nextPlayer() const;

    Player *currentPlayer() const;

    Player *getPlayerWon() const;

private:
    Board *_newBoard;
    Player *player1;
    Player *player2;
    Player *_currentPlayer;
    Player *_playerWon;
    set<Piece *> _whitePieces;
    set<Piece *> _blackPieces;
};

#include "game_impl.hpp"

#endif