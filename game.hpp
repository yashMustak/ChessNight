#ifndef game_header
#define game_header

#include<set>

#include "board.hpp"
#include "piece.hpp"
#include "player.hpp"

class Game{

    public:
        ~Game();

        static void initialize();

        static Player* nextPlayer();

        static Player* opponent(Player& thisPlayer);

    private:
        Game();

        static Player* player1;
        static Player* player2;
        static set<Piece*> whitePieces;
        static set<Piece*> blackPieces;
};

// #include "game_impl.hpp"

#endif