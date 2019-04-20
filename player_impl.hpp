/*
** Player Implementation
*/
Player::Player(string name, bool isWhite, King &myKing, set<Piece*> &myPieces) : 
_name(name), _isWhite(isWhite), _myKing(myKing), _myPieces(myPieces){
}

Player::~Player(){
}

void Player::changeName(string newName){
	_name = newName;
}

bool Player::makeMove(){
	
	string fromTile;
	string toTile;
	int fromX;
	int fromY;
	int toX;
	int toY;
	
	if(inCheck){
		cout<<_name<<" is in Check!"<<endl;
	}
	
	cout<<_name<<" enter your move (eg. d4 d6): ";
	cin>>fromTile;
	cin>>toTile;
	
	transform(fromTile.begin(), fromTile.end(), fromTile.begin(), ::tolower);
	transform(toTile.begin(), toTile.end(), toTile.begin(), ::tolower);
	
	fromX = (int)fromTile[0] - 97;
	fromY = 8 - (int)fromTile[1];
	
	toX = (int)toTile[0] - 97;
	toY = 8 - (int)toTile[1];
	
	while(fromX >= 8 || fromX < 0 ||
	   fromY >= 8 || fromX < 0 ||
	   toX >= 8 || toX < 0 ||
	   toY >= 8 || toY < 0){
	   	cout<<"Please enter valid coordinates on the board: ";
	   	
	   	cin>>fromTile;
		cin>>toTile;
		
		transform(fromTile.begin(), fromTile.end(), fromTile.begin(), ::tolower);
		transform(toTile.begin(), toTile.end(), toTile.begin(), ::tolower);
		
		fromX = (int)fromTile[0] - 97;
		fromY = 8 - (int)fromTile[1];
		
		toX = (int)toTile[0] - 97;
		toY = 8 - (int)toTile[1];
	}
	
	return Board::getBoard()->tileAt(fromX, fromY)->getPiece()->moveTo(
		*this, *(Board::getBoard()->tileAt(toX, toY)));
}

bool Player::inCheck(){
	bool check = false;
	set<Piece*> tempSet = Game::opponentOf(*this)->_myPieces;
	for(set<Piece*>::iterator itr = tempSet.begin(); itr != tempSet.end(); ++itr){
		if((Piece*)*itr->getLocation() && (Piece*)*itr->canMoveTo(*_myKing.getLocation())) check = true;
		else check = false;
	}
}

void Player::capture(Piece* capturePiece){
	capturePiece->setLocation(NULL);
	
	//Game::opponentOf(*this)->_myPieces.erase(capturePiece);
}