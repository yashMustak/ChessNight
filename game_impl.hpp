// implementation of Game

Game::Game() : _playerWon(NULL)
{
}

void Game::initialize()
{
    _newBoard = new Board;
    Piece *piecePtr;
    Tile *tilePtr;
    std::string setName;
    char check;

    // Queens declaration
    piecePtr = new Queen(false);
    tilePtr = _newBoard->tileAt(0, 3);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _blackPieces.insert(piecePtr);
    piecePtr = new Queen(true);
    tilePtr = _newBoard->tileAt(7, 3);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _whitePieces.insert(piecePtr);

    // Bishop declaration
    piecePtr = new Bishop(false);
    tilePtr = _newBoard->tileAt(0, 2);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _blackPieces.insert(piecePtr);
    piecePtr = new Bishop(false);
    tilePtr = _newBoard->tileAt(0, 5);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _blackPieces.insert(piecePtr);
    piecePtr = new Bishop(true);
    tilePtr = _newBoard->tileAt(7, 2);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _whitePieces.insert(piecePtr);
    piecePtr = new Bishop(true);
    tilePtr = _newBoard->tileAt(7, 5);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _whitePieces.insert(piecePtr);

    // Rook declaration
    piecePtr = new Rook(false);
    tilePtr = _newBoard->tileAt(0, 0);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _blackPieces.insert(piecePtr);
    piecePtr = new Rook(false);
    tilePtr = _newBoard->tileAt(0, 7);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _blackPieces.insert(piecePtr);
    piecePtr = new Rook(true);
    tilePtr = _newBoard->tileAt(7, 0);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _whitePieces.insert(piecePtr);
    piecePtr = new Rook(true);
    tilePtr = _newBoard->tileAt(7, 7);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _whitePieces.insert(piecePtr);

    // Knight declaration
    piecePtr = new Knight(false);
    tilePtr = _newBoard->tileAt(0, 1);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _blackPieces.insert(piecePtr);
    piecePtr = new Knight(false);
    tilePtr = _newBoard->tileAt(0, 6);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _blackPieces.insert(piecePtr);
    piecePtr = new Knight(true);
    tilePtr = _newBoard->tileAt(7, 1);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _whitePieces.insert(piecePtr);
    piecePtr = new Knight(true);
    tilePtr = _newBoard->tileAt(7, 6);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _whitePieces.insert(piecePtr);

    // Pawn declaration
    piecePtr = new Pawn(false);
    tilePtr = _newBoard->tileAt(1, 0);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _blackPieces.insert(piecePtr);
    piecePtr = new Pawn(false);
    tilePtr = _newBoard->tileAt(1, 1);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _blackPieces.insert(piecePtr);
    piecePtr = new Pawn(false);
    tilePtr = _newBoard->tileAt(1, 2);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _blackPieces.insert(piecePtr);
    piecePtr = new Pawn(false);
    tilePtr = _newBoard->tileAt(1, 3);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _blackPieces.insert(piecePtr);
    piecePtr = new Pawn(false);
    tilePtr = _newBoard->tileAt(1, 4);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _blackPieces.insert(piecePtr);
    piecePtr = new Pawn(false);
    tilePtr = _newBoard->tileAt(1, 5);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _blackPieces.insert(piecePtr);
    piecePtr = new Pawn(false);
    tilePtr = _newBoard->tileAt(1, 6);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _blackPieces.insert(piecePtr);
    piecePtr = new Pawn(false);
    tilePtr = _newBoard->tileAt(1, 7);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _blackPieces.insert(piecePtr);

    piecePtr = new Pawn(true);
    tilePtr = _newBoard->tileAt(6, 0);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _whitePieces.insert(piecePtr);
    piecePtr = new Pawn(true);
    tilePtr = _newBoard->tileAt(6, 1);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _whitePieces.insert(piecePtr);
    piecePtr = new Pawn(true);
    tilePtr = _newBoard->tileAt(6, 2);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _whitePieces.insert(piecePtr);
    piecePtr = new Pawn(true);
    tilePtr = _newBoard->tileAt(6, 3);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _whitePieces.insert(piecePtr);
    piecePtr = new Pawn(true);
    tilePtr = _newBoard->tileAt(6, 4);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _whitePieces.insert(piecePtr);
    piecePtr = new Pawn(true);
    tilePtr = _newBoard->tileAt(6, 5);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _whitePieces.insert(piecePtr);
    piecePtr = new Pawn(true);
    tilePtr = _newBoard->tileAt(6, 6);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _whitePieces.insert(piecePtr);
    piecePtr = new Pawn(true);
    tilePtr = _newBoard->tileAt(6, 7);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _whitePieces.insert(piecePtr);

    // King declaration
    piecePtr = new King(true);
    tilePtr = _newBoard->tileAt(7, 4);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _whitePieces.insert(piecePtr);

    player1 = new Player("White", true);
    std::cout << "Set name of palyer as \"White\"? (y/n): ";
    std::cin >> check;
    if (check == 'n')
    {
        cout << "Please enter your name: ";
        cin >> setName;
        player1->changeName(setName);
    }

    piecePtr = new King(false);
    tilePtr = _newBoard->tileAt(0, 4);
    piecePtr->setPosition(tilePtr);
    tilePtr->setPiece(piecePtr);
    _blackPieces.insert(piecePtr);

    player2 = new Player("Black", false);
    std::cout << "Set name of palyer as \"Black\"? (y/n): ";
    std::cin >> check;
    if (check == 'n')
    {
        cout << "Please enter your name: ";
        cin >> setName;
        player2->changeName(setName);
    }

    player1->setOppositePieces(&_blackPieces);
    player2->setOppositePieces(&_whitePieces);

    _currentPlayer = player1;
}

Board *Game::getBoard()
{
    return _newBoard;
}

void Game::setPlayerWon(Player *playerWon)
{
    _playerWon = playerWon;
}

Player *Game::nextPlayer() const
{
    if (_currentPlayer == player1)
        return player2;
    else
        return player1;
}

Player *Game::getPlayerWon() const
{
    return _playerWon;
}

void Game::setCurrentPlayer(Player *thisPlayer)
{
    _currentPlayer = thisPlayer;
}

Player *Game::currentPlayer() const
{
    return _currentPlayer;
}

Player *Game::opponentOf(Player *thisPlayer)
{
    if (thisPlayer == player1)
        return player2;
    else
        return player1;
}