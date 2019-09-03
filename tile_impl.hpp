// implementation of Tile

Tile::Tile(int x, int y, Board *inBoard) : _x(x), _y(y), _piece(NULL), _inBoard(inBoard)
{
}

void Tile::setPiece(Piece *piece)
{
    _piece = piece;
}

bool Tile::isEmpty()
{
    if (_piece == NULL)
        return true;
    else
        return false;
}

Piece *Tile::getPiece() const
{
    return _piece;
}

Board *Tile::getBoard() const
{
    return _inBoard;
}

int Tile::getX() const
{
    return _x;
}

int Tile::getY() const
{
    return _y;
}