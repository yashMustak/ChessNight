// implementation of Queen

Queen::Queen(bool isWhite) : Piece(isWhite)
{
}

bool Queen::canMoveTo(Tile *toTile)
{
    Tile *onTile = this->getPosition();

    Board *inBoard = toTile->getBoard();

    if (inBoard->isEmptyDiagonal(onTile, toTile))
    {
        return true;
    }
    else
    {
        if (inBoard->isEmptyHorizontal(onTile, toTile))
        {
            return true;
        }
        else
        {
            if (inBoard->isEmptyVertical(onTile, toTile))
            {
                return true;
            }
            return false;
        }
    }
}

void Queen::symbol()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (this->getColor())
    {
        SetConsoleTextAttribute(hConsole, 1); //15
        std::cout << "Q";
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 4); //240
        std::cout << "q";
    }
    SetConsoleTextAttribute(hConsole, 15);
}

int Queen::getPriority() const
{
    return _priority;
}