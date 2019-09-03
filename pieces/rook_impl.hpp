// implementation of Rook

Rook::Rook(bool isWhite) : Piece(isWhite)
{
}

bool Rook::canMoveTo(Tile *toTile)
{
    Tile *onTile = this->getPosition();

    Board *inBoard = toTile->getBoard();

    if (inBoard->isEmptyHorizontal(onTile, toTile))
        return true;
    else
    {
        if (inBoard->isEmptyVertical(onTile, toTile))
            return true;
    }
    return false;
}

void Rook::symbol()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (this->getColor())
    {
        SetConsoleTextAttribute(hConsole, 1); //15
        std::cout << "R";
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 4); //240
        std::cout << "r";
    }
    SetConsoleTextAttribute(hConsole, 15);
}

int Rook::getPriority() const
{
    return _priority;
}