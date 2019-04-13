/*
**	board implementation
*/
#include<cstdlib>

Board::Board(){
	for(int i = 0; i < _DIMENSION; i++){
		for(int j = 0; j < _DIMENSION; j++){
			_TileArr[i][j] = new Tile(i, j);
		}
	}
}

Board::~Board(){
	for(int i = 0; i < _DIMENSION; i++){
		for(int j = 0; j < _DIMENSION; j++){
			delete[] _TileArr[i][j];
		}
		delete[] _TileArr[i];
	}
	delete[] _TileArr;
}

Board* Board::getBoard(){
	if(_BOARD) return _BOARD;
	else _BOARD = new Board();
}

Tile* Board::tileAt(int x, int y) const{
	if(x >= 0 && x < 8 && y >= 0 && y < 8) return _TileArr[x][y];
}

bool Board::isClearVertical(Tile &from, Tile &to) const{
	
	int startX = from.getX();
	int startY = from.getY();
	int endX = to.getX();
	int endY = to.getY();
	int checkY;
	
	if(startX == endX){
		int increament = (endY - startY) / abs(endY - startY);
		checkY = startY + increament;
		Tile* check = _TileArr[startX][checkY];
		while (check->isEmpty() && checkY != endY){
			checkY = checkY + increament;
			check = _TileArr[startX][checkY];
		}
		if(checkY == endY) return true;
		else return false;
	}
}

bool Board::isClearHorizontal(Tile &from, Tile &to) const{
	
	int startX = from.getX();
	int startY = from.getY();
	int endX = to.getX();
	int endY = to.getY();
	int checkX;
	
	if(startY == endY){
		int increament = (endX - startX) / abs(endX - startX);
		checkX = startX + increament;
		Tile* check = _TileArr[checkX][startY];
		while (check->isEmpty() && checkX != endX){
			checkX = checkX + increament;
			check = _TileArr[checkX][startY];
		}
		if(checkX == endX) return true;
		else return false;
	}
}

bool Board::isClearDiagonal(Tile &from, Tile &to) const{
	
	int startX = from.getX();
	int startY = from.getY();
	int endX = to.getX();
	int endY = to.getY();
	int checkX;
	int checkY;
	
	if(abs(startY-endY) == abs(startX-endX)){
		int increament = (endX - startX) / abs(endX - startX);
		checkX = startX + increament;
		checkY = startY + increament;
		Tile* check = _TileArr[checkX][checkY];
		while (check->isEmpty() && checkX != endX){
			checkX = checkX + increament;
			checkY = checkY + increament;
			check = _TileArr[checkX][checkY];
		}
		if(checkX == endX) return true;
		else return false;
	}
}


/*
**	 	A B C D E F G H
** 	
**	1	r n b q k b n r  1
**	2	p p p p p p p p  2
**	3	- + - + - + - +  3
**	4	+ - + - + - + -  4
**	5	- + - + - + - +  5
**	6	+ - + - + - + -  6
**	7	P P P P P P P P  7
**	8	R N B Q K B N R  8
**	
**	 	A B C D E F G H
*/
void Board::display() const{
	
	cout<<" \tA B C D E F G H"<<endl<<endl;
	for(int i = 0; i < _DIMENSION; i++){
		for(int j = -1; j <= _DIMENSION; j++){
			if(j == -1) cout<<i+1<<"\t";
			else{
				if(j == 8) cout<<" "<<i+1;
				else{
					if(!_TileArr[i][j]->isEmpty) _TileArr[i][j]->getPiece->display();
					else{
						if(_TileArr[i][j]->getX % 2 == 0 && _TileArr[i][j]->getY % 2 == 0) cout<<"- ";
						else cout<<" +";
					}
				}
			}
		}
	}
	cout<<endl<<endl<<" \tA B C D E F G H";
}

