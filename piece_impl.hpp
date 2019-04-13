/*
** Piece implementation
*/
#include<iostream>

using namespace std;

Piece::Piece(bool isWhite) : _isWhite(isWhite), _tile(NULL){
	if(_isWhite) _color = 'W';
	else _color = 'B';
}

Piece::~Piece(){
}

bool Piece::moveTo(Player& byPlayer, Tile& toTile){
	
	bool validMove = false;	
	if(_isWhite == byPlayer.isWhite()){
		if(canMoveTo(toTile)){
			if(!byPlayer.inCheck()){
				if(toTile.isEmpty()){
					validMove = true;
					_tile = &toTile;
				}
				else{
					Piece* capturePiece = NULL;
					if(toTile.getPiece()->isWhite() != _isWhite){
						capturePiece = toTile.getPiece();
						capturePiece->setLocation(NULL);
						toTile.setPiece(this);
						_tile = &toTile;
						validMove = true;
						byPlayer.capture(capturePiece);
					}
					else validMove = false;
				}
			}
			else {
				// throw an error
				cout<<"This move will let the king in Check";
			}
		}
		else{
			// throw an error
			cout<<"This is an invalid move for this piece";
		}
	}
	else{
		// throw an error
		cout<<"This piece do not belong to current player";
	}
	
	return validMove;
}

char Piece::getColor() const{
	return _color;
}

bool Piece::isWhite() const{
	if(_isWhite) return true;
	else return false;
}

void Piece::setLocation(Tile* setTile){
	_tile = setTile;
}

Tile* Piece::getLocation() const{
	return _tile;
}
