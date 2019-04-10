/*
**	tile implementation
*/
#include"tile.hpp"

Tile::Tile(int X, int Y) : _posX(X), _posY(Y) {
	_piece = NULL;
}

void Tile::setPiece(Piece* piece){
	_piece = piece;
}

Piece* Tile::getPiece() const{
	return _piece;
}

bool Tile::isEmpty() const{
	return _piece;
}

int Tile::getX() const{
	return _posX;
}

int Tile::getY() const{
	return _posY;
}
