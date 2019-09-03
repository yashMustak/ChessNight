// Implementation of Piece

Piece::Piece(bool isWhite) : _isWhite(isWhite)
{
}

bool Piece::moveTo(bool isWhite, Tile *toTile)
{
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
            return false;
    }
    else
        return false;
}

void Piece::setPosition(Tile *tile)
{
    this->_currentTile = tile;
}

Tile *Piece::getPosition() const
{
    return _currentTile;
}

bool Piece::getColor() const
{
    return _isWhite;
}