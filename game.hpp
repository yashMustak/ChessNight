#ifndef game_header
#define game_header

#include<set>

#include "board.hpp"
#include "piece.hpp"
#include "player.hpp"

#if defined(__unix__)
#include "pieces/king.hpp"
#include "pieces/queen.hpp"
#include "pieces/bishop.hpp"
#include "pieces/rook.hpp"
#include "pieces/knight.hpp"
#include "pieces/pawn.hpp"

#elif defined(_WIN64)
#include "pieces\king.hpp"
#include "pieces\queen.hpp"
#include "pieces\bishop.hpp"
#include "pieces\rook.hpp"
#include "pieces\knight.hpp"
#include "pieces\pawn.hpp"

#elif defined(__APPLE__)
#include "pieces/king.hpp"
#include "pieces/queen.hpp"
#include "pieces/bishop.hpp"
#include "pieces/rook.hpp"
#include "pieces/knight.hpp"
#include "pieces/pawn.hpp"
#endif

class Game{

    public:
        ~Game();

        static void initialize();

        static Player* nextPlayer();

        static Player* opponentOf(Player& thisPlayer);

    private:
        Game();

        static Player* currentPlayer;
        static Player* player1;
        static Player* player2;
        static set<Piece*> whitePieces;
        static set<Piece*> blackPieces;
};

#include "game_impl.hpp"

#endif