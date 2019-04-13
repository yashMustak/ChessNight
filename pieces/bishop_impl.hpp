/*
** Bishop Implementation
*/
Bishop::Bishop(bool isWhite) : Piece(isWhite){
}

Bishop::~Bishop(){
}

int Bishop::getPriority() const{
    return 4;
}

bool Bishop::canMoveTo(Tile& toTile) const{
    bool validMove = false;
    int delX = abs(this->getLocation()->getX() - toTile.getX());
    int delY = abs(this->getLocation()->getY() - toTile.getY());

    if(delX == delY) validMove = true;
    
    return validMove;
}

void Bishop::display(){
    if(isWhite) cout<<"B";
    else cout<<"b";
}