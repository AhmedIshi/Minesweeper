#include "MinesweeperBox.h"


MinesweeperBox::MinesweeperBox()
{
	this->boxStatus = unopened;
	adjacentMines = 0;
    setMineStatus(false);
}

void MinesweeperBox::setMineStatus(bool mineStatus)
{
	this->mineStatus = mineStatus;
}

bool MinesweeperBox::getMineStatus()
{
	return mineStatus;
}

void MinesweeperBox::setAdjacentMines(int adjacentMines)
{
	this->adjacentMines = adjacentMines;
}

int MinesweeperBox::getAdjacentMines()
{
	return adjacentMines;
}

void MinesweeperBox::setBoxStatus( BoxStatus boxStatus )
{
	this->boxStatus = boxStatus;
}

BoxStatus MinesweeperBox::getBoxStatus()
{
	return this->boxStatus;
}

