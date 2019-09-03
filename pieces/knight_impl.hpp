// implementation of Knight

Knight::Knight(bool isWhite) : Piece(isWhite)
{
}

bool Knight::canMoveTo(Tile *toTile)
{
    int curX, curY, desX, desY;

    curX = this->getPosition()->getX();
    curY = this->getPosition()->getY();

    desX = toTile->getX();
    desY = toTile->getY();

    if (std::abs(desX - curX) + std::abs(desY - curY) == 3 && std::abs(desX - curX) != 0 && std::abs(desY - curY) != 0)
    {
        if (toTile->isEmpty())
            return true;
        else
        {
            if (toTile->getPiece()->getColor() != this->getColor())
                return true;
        }
        return false;
    }
    return false;
}

void Knight::symbol()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (this->getColor())
    {
        SetConsoleTextAttribute(hConsole, 1); //15
        std::cout << "N";
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 4); //240
        std::cout << "n";
    }
    SetConsoleTextAttribute(hConsole, 15);
}

int Knight::getPriority() const
{
    return _priority;
}