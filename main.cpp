#include "game.hpp"

int main()
{
    Game newGame;
    newGame.initialize();
    newGame.getBoard()->display();
    bool validMove = true;

    while (true)
    {
        cout << newGame.currentPlayer()->getName() << " make your move (eg. A5 B6): ";
        validMove = newGame.currentPlayer()->makeMove(newGame.getBoard());
        while (!validMove)
        {
            cout << "Invalid move please try again: ";
            validMove = newGame.currentPlayer()->makeMove(newGame.getBoard());
        }
        newGame.getBoard()->display();
        newGame.setCurrentPlayer(newGame.nextPlayer());

        if (newGame.getPlayerWon())
        {
            cout << "Congragulations !! " << newGame.getPlayerWon()->getName();
            break;
        }
    }
}