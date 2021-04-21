#include "Board.h"

Board::Board(int totalRows, int totalColumns)
{	    
		this->totalColumns = totalColumns;
		this->totalRows = totalRows;
}

bool Board::isValid(int totalRows, int totalColumns)
{
	if ((totalRows >= 0 && totalRows < this->totalRows) && (totalColumns >= 0 && totalColumns < this->totalColumns))
		return true;
	else
		return false;
}
