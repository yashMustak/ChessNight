/*
** King Implementation
*/
King::King(bool isWhite) : RestrictedPiece(isWhite){
}

King::~King(){
}

int King::getPriority() const{
    return 1;
}

bool King::canMoveTo ( Tile& toTile ) const{
    bool validMove = false;
    int delX = abs(this->getLocation()->getX() - toTile.getX());
    int delY = abs(this->getLocation()->getY() - toTile.getY());

    if ( delX == 1 && delY == 0 ) validMove = true;
    else{
        if ( delX == 0 && delY == 1 ) validMove = true;
        else{
            if ( delX == 1 && delY == 1 ) validMove = true;
        }
    }

    return validMove;
}

void King::display(){
    if(isWhite) cout<<"K";
    else cout<<"k";
}