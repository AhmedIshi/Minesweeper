#include "Box.h"

Box::Box()
{
	rowNum = 0;
	columnNum = 0;
}

void Box::setColumnNumber( int columnNum)
{
	this->columnNum = columnNum;
}

int Box::getColumnNumber()
{
	return this->columnNum;
}

void Box::setRowNumber( int rowNum )
{
	this->rowNum = rowNum;
}

int Box::getRowNumber()
{
	return this->rowNum;
}
