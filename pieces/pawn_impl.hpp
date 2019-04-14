/*
** Pawn Implementation
*/
Pawn::Pawn(bool isWhite) : RestrictedPiece(isWhite), _promotedTo(NULL){
}

Pawn::~Pawn(){
}

int Pawn::getPriority() const{
    return 5;
}

bool Pawn::moveTo(Player& byPlayer, Tile& toTile){
    
    bool valid = false;
    
    if(_promotedTo){
        valid = _promotedTo->moveTo(byPlayer, toTile);

        if(valid){
            getLocation()->setPiece(NULL);
            setLocation(&toTile);
            toTile.setPiece(this);
        }
    }
    else{
        valid = RestrictedPiece::moveTo(byPlayer, toTile);

        if(valid){
            if(Board::getBoard()->isEndRow(&toTile)){
                char pieceInput;
                cout<<"Select the Piece to which this pawn to be converted (type Q-Queen, N-Knight, B-Bishp, R-Rook, P-Pawn): ";
                cin>>pieceInput;
                switch (pieceInput)
                {
                case 'Q':
                    _promotedTo = new Queen(isWhite);
                    _promotedTo->setLocation(&toTile);
                    getLocation()->setPiece(NULL);
                    toTile.setPiece(_promotedTo);
                    break;

                case 'N':
                    _promotedTo = new Knight(isWhite);
                    _promotedTo->setLocation(&toTile);
                    getLocation()->setPiece(NULL);
                    toTile.setPiece(_promotedTo);
                    break;

                case 'R':
                    _promotedTo = new Rook(isWhite);
                    _promotedTo->setLocation(&toTile);
                    getLocation()->setPiece(NULL);
                    toTile.setPiece(_promotedTo);
                    break;

                case 'B':
                    _promotedTo = new Bishop(isWhite);
                    _promotedTo->setLocation(&toTile);
                    getLocation()->setPiece(NULL);
                    toTile.setPiece(_promotedTo);
                    break;
                
                case 'P':
                    getLocation()->setPiece(NULL);
                    setLocation(&toTile);
                    toTile.setPiece(this);
                    break;
                
                default:
                    cout<<"Incorrect input: Retaining as Pawn";
                    break;
                }
            }
        }
    }
    return valid;
}

bool Pawn::canMoveTo(Tile& toTile) const{
    bool validMove = false;
    int delX = abs(this->getLocation()->getX() - toTile.getX());
    int delY = abs(this->getLocation()->getY() - toTile.getY());

    if(_promotedTo){
        validMove = _promotedTo->canMoveTo(toTile);
    }
    else{
        if(!isWhite()){
            delY *= -1;
        }
        if(toTile.isEmpty()){
            if(delX == 0 && delY == 1) validMove = true;
            else{
                if(!hasMoved()){
                    if(Board::getBoard()->isClearVertical(*this->getLocation(), toTile)){
                        if(delX == 0 && delY == 2) validMove = true;
                    }
                }
            }
        }
        if(toTile.getPiece()->isWhite() != this->isWhite()){
            if(abs(delX) == 1 && delY == 1) validMove = true;
        }
    }
    
    return validMove;
}

void Pawn::display(){
    if(isWhite()) cout<<"P";
    else cout<<"p";
}