/*
** Queen Implementation
*/
Queen::Queen(bool isWhite) : Piece(isWhite){
}

Queen::~Queen(){
}

int Queen::getPriority() const{
    return 2;
}

bool Queen::canMoveTo(Tile& toTile) const{
    bool validMove = false;
    int delX = abs(this->getLocation()->getX() - toTile.getX());
    int delY = abs(this->getLocation()->getY() - toTile.getY());

    if(Board::getBoard()->isClearDiagonal(*this->getLocation(), toTile)){
        if(delX == delY) validMove = true;
    }
    else{
        if(Board::getBoard()->isClearHorizontal(*this->getLocation(), toTile)){
            if(delX == 0) validMove = true;
        }
        else{
            if(Board::getBoard()->isClearVertical(*this->getLocation(), toTile)){
                if(delY == 0) validMove = true;
            }
        }
    }
    
    return validMove;
}

void Queen::display(){
    if(isWhite()) cout<<"Q";
    else cout<<"q";
}