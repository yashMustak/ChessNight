/*
** Rook Implementation
*/
Rook::Rook(bool isWhite) : Piece(isWhite){
}

Rook::~Rook(){
}

int Rook::getPriority() const{
    return 4;
}

bool Rook::canMoveTo(Tile& toTile) const{
    bool validMove = false;
    int delX = abs(this->getLocation()->getX() - toTile.getX());
    int delY = abs(this->getLocation()->getY() - toTile.getY());

    if(Board::getBoard()->isClearHorizontal(*this->getLocation(), toTile)){
            if(delX == 0) validMove = true;
    }
    else{
        if(Board::getBoard()->isClearVertical(*this->getLocation(), toTile)){
            if(delY == 0) validMove = true;
        }
    }
    
    return validMove;
}

void Rook::symbol(){
    if(isWhite()) cout<<"R";
    else cout<<"r";
}
