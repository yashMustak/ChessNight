#ifndef tile_header
#define tile_header

#include<iostream>

class Piece;

using namespace std;

class Tile{
	
	const int _posX;
	const int _posY;
	Piece* _piece;
	
	public:
		
		Tile ( int X, int Y );
		
		void setPiece ( Piece* piece );
		
		Piece* getPiece () const;
		
		bool isEmpty () const;
		
		int getX () const;
		
		int getY () const;
};

#endif
