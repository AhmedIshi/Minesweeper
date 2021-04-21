#include "Score.h"
#include <windows.h>
#include <iostream>

void Score::timer(void)
{
	int i, seconds;

	for (i = 0; i >= 0; ++i)
	{
		for (seconds = 0; seconds >= 0; ++seconds)
		{

			Sleep(1000); //System pauses for 1000 milliseconds i.e. 1 second.
		
		}
	}

	calculateScore(seconds);
	
}

void Score::calculateScore (int seconds)
{
	this->score = seconds * 10;
}
