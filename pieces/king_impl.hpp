/*
** King Implementation
*/
King::King(bool isWhite) : Piece(isWhite){
}

King::~King(){
}

int King::getPriority() const{
    return 1;
}

bool King::moveTo(Player& byPlayer, Tile& toTile){
    
    bool valid = Piece::moveTo(byPlayer, toTile);

    if(valid && !_moved){
        _moved = true;
    }

    return valid;
}

bool King::canMoveTo ( Tile& toTile ) const{
    bool validMove = false;
    int delX = abs(this->getLocation()->getX() - toTile.getX());
    int delY = abs(this->getLocation()->getY() - toTile.getY());

    if(toTile.isEmpty()){
        if ( delX == 1 && delY == 0 ) validMove = true;
        else{
            if ( delX == 0 && delY == 1 ) validMove = true;
            else{
                if ( delX == 1 && delY == 1 ) validMove = true;
            }
        }
    }

    return validMove;
}

bool King::hasMoved() const{
    return _moved;
}

void King::symbol(){
    if(isWhite()) cout<<"K";
    else cout<<"k";
}
