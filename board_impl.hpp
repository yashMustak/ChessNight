// implementation of Board

Board::Board()
{
    for (int i = 0; i < _DIMENSION; i++)
    {
        for (int j = 0; j < _DIMENSION; j++)
        {
            _tileArr[i][j] = new Tile(i, j, this);
        }
    }
}

bool Board::isEmptyVertical(Tile *from, Tile *to) const
{
    int fromX, fromY, toX, toY;

    fromX = from->getX();
    fromY = from->getY();
    toX = to->getX();
    toY = to->getY();

    if (fromY == toY)
    {
        for (int i = fromX + 1; i < toX; i++)
        {
            if (!_tileArr[i][toY]->isEmpty())
                return false;
        }
        if (!to->isEmpty())
        {
            if (_tileArr[toX][toY]->getPiece()->getColor() == from->getPiece()->getColor())
                return false;
        }
        return true;
    }
    else
        return false;
}

bool Board::isEmptyHorizontal(Tile *from, Tile *to) const
{
    int fromX, fromY, toX, toY;

    fromX = from->getX();
    fromY = from->getY();
    toX = to->getX();
    toY = to->getY();

    if (fromX == toX)
    {

        for (int i = fromY + 1; i < toY; i++)
        {
            if (!_tileArr[fromX][i]->isEmpty())
                return false;
        }
        if (!to->isEmpty())
        {
            if (_tileArr[toX][toY]->getPiece()->getColor() == from->getPiece()->getColor())
                return false;
        }
        return true;
    }
    else
        return false;
}

bool Board::isEmptyDiagonal(Tile *from, Tile *to) const
{
    int fromX, fromY, toX, toY;

    fromX = from->getX();
    fromY = from->getY();
    toX = to->getX();
    toY = to->getY();

    if (std::abs(fromX - toX) == std::abs(fromY - toY))
    {
        int increament = (toX - fromX) / std::abs(toX - fromX);
        int diff = abs(toX - fromX);
        for (int i = 1; i < diff - 1; i++)
        {
            if (!_tileArr[fromX + increament][fromY + increament]->isEmpty())
                return false;
        }
        if (!to->isEmpty())
        {
            if (_tileArr[toX][toY]->getPiece()->getColor() == from->getPiece()->getColor())
                return false;
        }
        return true;
    }
    else
        return false;
}

Tile *Board::tileAt(int x, int y) const
{
    return _tileArr[x][y];
}

using namespace std;
/*
**	 	A B C D E F G H
** 	
**	1	r n b q k b n r 	1
**	2	p p p p p p p p 	2
**	3	- + - + - + - + 	3
**	4	+ - + - + - + - 	4
**	5	- + - + - + - + 	5
**	6	+ - + - + - + - 	6
**	7	P P P P P P P P 	7
**	8	R N B Q K B N R 	8
**	
**	 	A B C D E F G H
*/
void Board::display()
{
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << " \tA B C D E F G H" << endl
         << endl;
    for (int i = 0; i < _DIMENSION; i++)
    {
        for (int j = -1; j <= _DIMENSION; j++)
        {
            if (j == -1)
                cout << i + 1 << "\t";
            else
            {
                if (j == _DIMENSION)
                    cout << "\t" << i + 1 << endl;
                else
                {
                    if (!_tileArr[i][j]->isEmpty())
                    {
                        _tileArr[i][j]->getPiece()->symbol();
                        cout << " ";
                    }
                    else
                    {
                        if (i % 2 == 0 && j % 2 == 0)
                        {
                            SetConsoleTextAttribute(hConsole, 8);
                            cout << "- ";
                            SetConsoleTextAttribute(hConsole, 15);
                        }
                        else
                        {
                            if (i % 2 != 0 && j % 2 != 0)
                            {
                                SetConsoleTextAttribute(hConsole, 8);
                                cout << "- ";
                                SetConsoleTextAttribute(hConsole, 15);
                            }
                            else
                            {
                                SetConsoleTextAttribute(hConsole, 15);
                                cout << "+ ";
                            }
                        }
                    }
                }
            }
        }
    }
    cout << endl
         << endl
         << " \tA B C D E F G H" << endl;
}