// implementation of Bishop

Bishop::Bishop(bool isWhite) : Piece(isWhite)
{
}

bool Bishop::canMoveTo(Tile *toTile)
{
    Tile *onTile = this->getPosition();

    Board *inBoard = toTile->getBoard();

    if (inBoard->isEmptyDiagonal(onTile, toTile))
    {
        return true;
    }
    return false;
}

void Bishop::symbol()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (this->getColor())
    {
        SetConsoleTextAttribute(hConsole, 1); //15
        std::cout << "B";
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 4); //240
        std::cout << "b";
    }
    SetConsoleTextAttribute(hConsole, 15);
}

int Bishop::getPriority() const
{
    return _priority;
}