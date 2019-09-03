// implementation of Pawn

Pawn::Pawn(bool isWhite) : Piece(isWhite)
{
}

bool Pawn::moveTo(bool isWhite, Tile *toTile)
{
    bool ret = false;

    if (isWhite == this->getColor())
    {
        if (this->canMoveTo(toTile))
        {
            if (!toTile->isEmpty())
            {
                delete toTile->getPiece();
            }
            this->getPosition()->setPiece(NULL);
            this->setPosition(toTile);
            toTile->setPiece(this);

            if (toTile->getX() == 0)
            {
                char newPiece;
                std::cout << "Select the Piece to which this pawn to be converted: ";
                std::cin >> newPiece;
                switch (newPiece)
                {
                case 'Q':
                {
                    Queen *newQueen = new Queen(isWhite);
                    newQueen->setPosition(toTile);
                    toTile->setPiece(newQueen);
                    delete this;
                    break;
                }

                case 'R':
                {
                    Rook *newRook = new Rook(isWhite);
                    newRook->setPosition(toTile);
                    toTile->setPiece(newRook);
                    delete this;
                    break;
                }

                case 'N':
                {
                    Knight *newKnight = new Knight(isWhite);
                    newKnight->setPosition(toTile);
                    toTile->setPiece(newKnight);
                    delete this;
                    break;
                }

                case 'B':
                {
                    Bishop *newBishop = new Bishop(isWhite);
                    newBishop->setPosition(toTile);
                    toTile->setPiece(newBishop);
                    delete this;
                    break;
                }

                default:
                {
                    std::cout << "Incorrect input: Retaining as Pawn" << std::endl;
                    break;
                }
                }
            }
            ret = true;
        }
    }
    if (!_moved)
        _moved = true;
    return ret;
}

bool Pawn::canMoveTo(Tile *toTile)
{
    int curX, curY, toX, toY;

    Tile *onTile = this->getPosition();

    Board *inBoard = toTile->getBoard();

    bool validMove = false;
    int delX = toTile->getX() - this->getPosition()->getX();
    int delY = toTile->getY() - this->getPosition()->getY();

    if (this->getColor())
    {
        delX *= -1;
    }
    if (toTile->isEmpty())
    {
        if (delY == 0 && delX == 1)
            validMove = true;
        else
        {
            if (!this->hasMoved())
            {
                if (inBoard->isEmptyVertical(onTile, toTile))
                {
                    if (delY == 0 && delX == 2)
                        validMove = true;
                }
            }
        }
    }
    else
    {
        if (toTile->getPiece()->getColor() != this->getColor())
        {
            if (abs(delY) == 1 && delX == 1)
                validMove = true;
        }
    }
    return validMove;
}

void Pawn::symbol()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (this->getColor())
    {
        SetConsoleTextAttribute(hConsole, 1); //15
        std::cout << "P";
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 4); //240
        std::cout << "p";
    }
    SetConsoleTextAttribute(hConsole, 15);
}

bool Pawn::hasMoved() const
{
    return _moved;
}

int Pawn::getPriority() const
{
    return _priority;
}