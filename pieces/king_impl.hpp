// implementation of King

King::King(bool isWhite) : Piece(isWhite)
{
}

bool King::moveTo(bool isWhite, Tile *toTile)
{
    if (!_moved)
        _moved = true;

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
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool King::canMoveTo(Tile *toTile)
{
    int curX, curY, desX, desY;

    curX = this->getPosition()->getX();
    curY = this->getPosition()->getY();

    desX = toTile->getX();
    desY = toTile->getY();

    if (std::abs(curX - desX) <= 1 && std::abs(curY - desY) <= 1)
    {
        if (toTile->isEmpty())
        {
            return true;
        }
        else
        {
            if (toTile->getPiece()->getColor() != this->getColor())
                return true;
            else
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
}

void King::symbol()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (this->getColor())
    {
        SetConsoleTextAttribute(hConsole, 1); //15
        std::cout << "K";
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 4); //240
        std::cout << "k";
    }
    SetConsoleTextAttribute(hConsole, 15);
}

bool King::hasMoved() const
{
    return _moved;
}

int King::getPriority() const
{
    return _priority;
}