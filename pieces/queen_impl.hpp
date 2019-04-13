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

    if(delX == delY) validMove = true;
    else{
        if(delX == 0) validMove = true;
        else{
            if(delY == 0) validMove = true;
        }
    }
    
    return validMove;
}

void Queen::display(){
    if(isWhite) cout<<"Q";
    else cout<<"q";
}