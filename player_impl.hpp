// implementation of Player

Player::Player(std::string name, bool isWhite) : _name(name), _isWhite(isWhite)
{
}

bool Player::makeMove(Board *thisBoard)
{
    std::string fromTile;
    std::string toTile;

    Tile *tilePtr;
    Piece *thisPiece;
    Piece *toPiece = NULL;

    bool makeMove = false;

    int fromX, fromY, toX, toY;

    if (this->inCheck())
    {
        std::cout << this->getName() << " is in check" << std::endl;
    }

    std::cin >> fromTile;
    std::cin >> toTile;

    if (fromTile[0] < 97)
    {
        fromY = (int)fromTile[0] - 65;
    }
    else
        fromY = (int)fromTile[0] - 97;
    fromX = (int)fromTile[1] - 49;

    if (toTile[0] < 97)
    {
        toY = (int)toTile[0] - 65;
    }
    else
        toY = (int)toTile[0] - 97;
    toX = (int)toTile[1] - 49;

    if (fromX < 0 || fromX > 7 || fromY < 0 || fromY > 7 || toX < 0 || toX > 7 || toY < 0 || toY > 7)
    {
        makeMove = false;
    }
    else
    {
        thisPiece = thisBoard->tileAt(fromX, fromY)->getPiece();
        tilePtr = thisBoard->tileAt(toX, toY);
        if (!tilePtr->isEmpty())
        {
            if (tilePtr->getPiece()->getColor() != thisPiece->getColor())
            {
                toPiece = tilePtr->getPiece();
            }
        }

        tilePtr = thisBoard->tileAt(fromX, fromY);
        if (!thisPiece)
        {
            makeMove = false;
        }
        else
        {
            tilePtr = thisBoard->tileAt(toX, toY);
            if (this->isValidMove(thisPiece, tilePtr))
            {
                makeMove = thisPiece->moveTo(this->getColor(), tilePtr);
            }
            else
                makeMove = false;
        }
    }
    if (makeMove)
    {
        if (toPiece)
        {
            set<Piece *>::iterator itr;
            for (itr = _oppositePieces->begin(); itr != _oppositePieces->end(); ++itr)
            {
                if (*itr == toPiece)
                {
                    _oppositePieces->erase(itr);
                    break;
                }
            }
            return makeMove;
        }
    }
}

bool Player::isValidMove(Piece *thisPiece, Tile *toTile)
{
    Tile *currentPosition = thisPiece->getPosition();
    Piece *destPiece = NULL;

    if (!toTile->isEmpty())
    {
        destPiece = toTile->getPiece();
    }

    if (thisPiece->canMoveTo(toTile))
    {
        thisPiece->setPosition(toTile);
        toTile->setPiece(thisPiece);
        currentPosition->setPiece(NULL);

        if (this->inCheck())
        {
            currentPosition->setPiece(thisPiece);
            thisPiece->setPosition(currentPosition);
            toTile->setPiece(destPiece);

            return false;
        }
        else
        {
            currentPosition->setPiece(thisPiece);
            thisPiece->setPosition(currentPosition);
            toTile->setPiece(destPiece);

            return true;
        }
    }
    else
    {
        return false;
    }
}

bool Player::inCheck()
{
    // std::set<Piece *>::iterator itr;
    // Piece *tempPiece;

    // for (itr = _oppositePieces->begin(); itr != _oppositePieces->end(); ++itr)
    // {
    //     tempPiece = *itr;
    //     // //testing
    //     tempPiece->symbol();
    //     // //end testing
    //     if (tempPiece->canMoveTo(this->getKing()->getPosition()))
    //         return true;
    //     itr++;
    // }
    // //testing
    // cout << "ending incheck" << endl;
    // //end testing
    return false;
}

void Player::changeName(std::string newName)
{
    _name = newName;
}

void Player::setOppositePieces(set<Piece *> *oppositePieces)
{
    _oppositePieces = oppositePieces;
}

bool Player::getColor() const
{
    return _isWhite;
}

set<Piece *> Player::getPieceSet() const
{
    return _myPieces;
}

set<Piece *> *Player::getOppositePieces() const
{
    return _oppositePieces;
}

King *Player::getKing() const
{
    return _myKing;
}

std::string Player::getName() const
{
    return _name;
}

std::set<Piece *> Player::getPeices() const
{
    return _myPieces;
}

std::set<Piece *> Player::getCaptured() const
{
    return _capturedPieces;
}