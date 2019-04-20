/*
** Game implementation
*/
Game::~Game(){
    for(set<Piece*>::iterator itr = whitePieces.begin(); itr != whitePieces.end(); ++itr){
        delete *itr;
    }
    whitePieces.clear();
    for(set<Piece*>::iterator itr = blackPieces.begin(); itr != blackPieces.end(); ++itr){
        delete *itr;
    }
    blackPieces.clear();

    delete player1;
    delete player2;
}

void Game::initialize(){
    Piece* piecePtr;
    Tile* tilePtr;
    string setName;
    char check;

    whitePieces = *(new set<Piece*>);
    blackPieces = *(new set<Piece*>);

    // Queens creation for both colors
    piecePtr = new Queen(false);
    tilePtr = Board::getBoard()->tileAt(3, 0);
    piecePtr->setLocation(tilePtr);
    tilePtr->setPiece(piecePtr);
    blackPieces.insert(piecePtr);
    piecePtr = new Queen(true);
    tilePtr = Board::getBoard()->tileAt(3, 7);
    piecePtr->setLocation(tilePtr);
    tilePtr->setPiece(piecePtr);
    whitePieces.insert(piecePtr);

    // Bishops
    piecePtr = new Bishop(false);
    tilePtr = Board::getBoard()->tileAt(2, 0);
    piecePtr->setLocation(tilePtr);
    tilePtr->setPiece(piecePtr);
    blackPieces.insert(piecePtr);
    piecePtr = new Bishop(false);
    tilePtr = Board::getBoard()->tileAt(5, 0);
    piecePtr->setLocation(tilePtr);
    tilePtr->setPiece(piecePtr);
    blackPieces.insert(piecePtr);
    piecePtr = new Bishop(true);
    tilePtr = Board::getBoard()->tileAt(2, 7);
    piecePtr->setLocation(tilePtr);
    tilePtr->setPiece(piecePtr);
    whitePieces.insert(piecePtr);
    piecePtr = new Bishop(true);
    tilePtr = Board::getBoard()->tileAt(5, 7);
    piecePtr->setLocation(tilePtr);
    tilePtr->setPiece(piecePtr);
    whitePieces.insert(piecePtr);

    // Knight
    piecePtr = new Knight(false);
    tilePtr = Board::getBoard()->tileAt(1, 0);
    piecePtr->setLocation(tilePtr);
    tilePtr->setPiece(piecePtr);
    blackPieces.insert(piecePtr);
    piecePtr = new Knight(false);
    tilePtr = Board::getBoard()->tileAt(6, 0);
    piecePtr->setLocation(tilePtr);
    tilePtr->setPiece(piecePtr);
    blackPieces.insert(piecePtr);
    piecePtr = new Knight(true);
    tilePtr = Board::getBoard()->tileAt(1, 7);
    piecePtr->setLocation(tilePtr);
    tilePtr->setPiece(piecePtr);
    whitePieces.insert(piecePtr);
    piecePtr = new Knight(true);
    tilePtr = Board::getBoard()->tileAt(6, 7);
    piecePtr->setLocation(tilePtr);
    tilePtr->setPiece(piecePtr);
    whitePieces.insert(piecePtr);

    // Rook
    piecePtr = new Rook(false);
    tilePtr = Board::getBoard()->tileAt(0, 0);
    piecePtr->setLocation(tilePtr);
    tilePtr->setPiece(piecePtr);
    blackPieces.insert(piecePtr);
    piecePtr = new Rook(false);
    tilePtr = Board::getBoard()->tileAt(7, 0);
    piecePtr->setLocation(tilePtr);
    tilePtr->setPiece(piecePtr);
    blackPieces.insert(piecePtr);
    piecePtr = new Rook(true);
    tilePtr = Board::getBoard()->tileAt(0, 7);
    piecePtr->setLocation(tilePtr);
    tilePtr->setPiece(piecePtr);
    whitePieces.insert(piecePtr);
    piecePtr = new Rook(true);
    tilePtr = Board::getBoard()->tileAt(7, 7);
    piecePtr->setLocation(tilePtr);
    tilePtr->setPiece(piecePtr);
    whitePieces.insert(piecePtr);

    for(int i = 0; i<8; i++){
        piecePtr = new Pawn(false);
        tilePtr = Board::getBoard()->tileAt(i, 1);
        piecePtr->setLocation(tilePtr);
        tilePtr->setPiece(piecePtr);
        blackPieces.insert(piecePtr);
        piecePtr = new Pawn(true);
        tilePtr = Board::getBoard()->tileAt(i, 6);
        piecePtr->setLocation(tilePtr);
        tilePtr->setPiece(piecePtr);
        whitePieces.insert(piecePtr);
    }

    piecePtr = new King(false);
    tilePtr = Board::getBoard()->tileAt(4, 0);
    piecePtr->setLocation(tilePtr);
    tilePtr->setPiece(piecePtr);
    blackPieces.insert(piecePtr);

    player1 = new Player("Black", false, piecePtr, blackPieces);
    cout<<"Set name of palyer as Black? (y/n): ";
    cin>>check;
    if(check == 'n'){
        cout<<"Please enter your name: ";
        cin>>setName;
        player1->changeName(setName);
    }

    piecePtr = new King(true);
    tilePtr = Board::getBoard()->tileAt(4, 7);
    piecePtr->setLocation(tilePtr);
    tilePtr->setPiece(piecePtr);
    whitePieces.insert(piecePtr);

    player2 = new Player("White", true, piecePtr, whitePieces);
    cout<<"Set name of palyer as White? (y/n): ";
    cin>>check;
    if(check == 'n'){
        cout<<"Please enter your name: ";
        cin>>setName;
        player2->changeName(setName);
    }

    currentPlayer = player2;
}

Player* Game::nextPlayer(){
    currentPlayer = opponentOf(*currentPlayer);
    return currentPlayer;
}

Player* Game::opponentOf(Player& thisPlayer){
    Player* opponent;
    
    if(thisPlayer.isWhite() == player1->isWhite()) opponent = player2;
    else opponent = player1;

    return opponent;
}