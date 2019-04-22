#include <iostream>

#include "game.hpp"
#include "board.hpp"

int main(int argc, char * const argv[]){
    Player* currentPlayer = NULL;

    Game::initialize();
    Board::getBoard()->display();

    while (true)
    {
        currentPlayer = Game::nextPlayer();
        while(!currentPlayer->makeMove()){
            cerr << "Invalid move... Try again" << endl;
        }
        Board::getBoard()->display();
    }
    
}