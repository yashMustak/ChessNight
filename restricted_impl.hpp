/*
** RestrictedPiece implementation
*/

RestrictedPiece::RestrictedPiece(bool isWhite) : Piece(isWhite){
}

RestrictedPiece::~RestrictedPiece(){
}

bool RestrictedPiece::moveTo(Player& byPlayer, Tile& toTile){
    
    bool valid = Piece::moveTo(byPlayer, toTile);

    if(valid && !_moved){
        _moved = true;
    }

    return valid;
}

bool RestrictedPiece::hasMoved() const{
    return _moved;
}