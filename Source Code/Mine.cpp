#include "Mine.h"
#include <stdlib.h>
#include <ctime>


Mine::Mine()
{
	mineStatus = true;
}

void Mine::setMineStatus(bool mineStatus)
{
	this->mineStatus = mineStatus;
}

bool Mine::getMineStatus()
{
	return mineStatus;
}