/*
** Knight Implementation
*/
Knight::Knight(bool isWhite) : Piece(isWhite){
}

Knight::~Knight(){
}

int Knight::getPriority() const{
    return 4;
}

bool Knight::canMoveTo(Tile& toTile) const{
    bool validMove = false;
    int delX = abs(this->getLocation()->getX() - toTile.getX());
    int delY = abs(this->getLocation()->getY() - toTile.getY());

    if( delX + delY == 3 && delX != 0 && delY != 0 ) validMove = true;
    
    return validMove;
}

void Knight::display(){
    if(isWhite) cout<<"N";
    else cout<<"n";
}