#ifndef player_header
#define player_header

#include<iostream>
#include<set>
#include "piece.hpp"

class Player{
	
	public:
		Player(string name, bool isWhite, King &myKing, set<Piece*> &myPieces);
		
		~Player();
		
		void changeName(string newName);
		
		bool makeMove();
		
		bool inCheck();
		
		void capture(Piece* capturePiece);
		
		string getName() const;
		
		bool isWhite() const;
		
		int score() const;
		
		set<Piece*>* getMyPieces() const;
		
		King* getKing() const;

	private:

		string _name;
		bool _isWhite;
		King _myKing;
		set<Piece*> _myPieces;
};

#endif
