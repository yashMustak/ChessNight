#ifndef piece_header
#define piece_header

#include<iostream>

#include "tile.hpp"
#include "board.hpp"
#include "player.hpp"

using namespace std;

class Piece{
	
	public:
		
		/*
		**	Creates a piece
		**	
		**	@params: (bool) colour boolean
		**	@return: NA
		*/
		Piece(bool isWhite);
		
		/*
		**	Destructor in case if piece is dead
		**	
		**	@params: NA
		**	@return: NA
		*/
		virtual ~Piece();
		
		/*
		**	Verify wether the player plays its own pieces
		**	
		**	@params: (Player object), (Tile object)
		**	@return: (boolean) true if valid
		*/	
		virtual bool moveTo ( Player &byPlayer, Tile &toTile );
		
		/*
		**	Verify the valid move according to the piece
		**	
		**	@params: (Tile object)
		**	@return: (boolean) true if valid
		*/
		virtual bool canMoveTo ( Tile &ToTile );
		
		/*
		**	Return colour name
		**	
		**	@params: ()
		**	@return: (char) "W" for white and "B" for black
		*/
		char getColor() const;
		
		/*
		**	Verify if piece is white or not
		**	
		**	@params: ()
		**	@return: (boolean) true if valid
		*/
		bool isWhite() const;
		
		virtual void display();
		
		void setLocation(Tile* setTile);
		
		Tile* getLocation();
		
		virtual int getPriority();
};


#endif
