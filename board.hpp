#ifndef board_header
#define board_header

#include<ostream>
#include"tile.hpp"

using namespace std;

class Board{
	
	Board ();
	
	static Board* _BOARD;
	static const int _DIMENSION = 8;
	Tile* _TileArr[_DIMENSION][_DIMENSION];
	
	public:
		
		~Board();
		
		static Board* getBoard ();
		
		Tile* tileAt ( int x, int y ) const;
		
		bool isClearVertical ( Tile &from, Tile &to ) const;
		
		bool isClearHorizontal ( Tile &from, Tile &to ) const;
		
		bool isClearDiagonal ( Tile &from, Tile &to ) const;

		bool isEndRow(Tile* thisTile) const;
		
		void display() const;
};

#include"board_impl.hpp"

#endif
