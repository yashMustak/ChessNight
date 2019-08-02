#ifndef player_header
#define player_header

#include <iostream>
#include <set>
#include <iterator>
//#include "common.hpp"
#include "piece.hpp"
#include "board.hpp"
#include "game.hpp"

#if defined(__unix__)
#include "pieces/king.hpp"

#elif defined(_WIN64)
#include "pieces\king.hpp"

#elif defined(__APPLE__)
#include "pieces/king.hpp"
#endif

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
		King& _myKing;
		set<Piece*>& _myPieces;
		set<Piece*> _captured;
};

#include"player_impl.hpp"

#endif
