/*
** Pawn Implementation
*/
Pawn::Pawn(bool isWhite) : Piece(isWhite){
}

Pawn::~Pawn(){
}

int Pawn::getPriority() const{
    return 5;
}

bool Pawn::canMoveTo(Tile& toTile) const{
    bool validMove = false;
    int delX = abs(this->getLocation()->getX() - toTile.getX());
    int delY = abs(this->getLocation()->getY() - toTile.getY());

    
    
    return validMove;
}

void Pawn::display(){
    if(isWhite) cout<<"P";
    else cout<<"p";
}