#include "Screen.h"
#include <iostream>
#include <Windows.h>

void Screen::setCursor( int x, int y )
{
	HANDLE handle;
	COORD coordinates;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(handle, coordinates);
}

void Screen::clearScreen(void)
{
	system("cls");
}

void Screen::printInfo(void)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

	setCursor(2, 15);
	std::cout << "+ " << "for Unopened Boxes";

	setCursor(2, 17);
	std::cout << "(0 -- 8) " << "for number of adjacent mines";

	setCursor(2, 19);
	std::cout << "F " << "for flag Boxes";

	setCursor(2, 21);
	std::cout << "* " << "for mine ";
}

void Screen::minesweeperLogo(void)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

	setCursor(52, 0);

	for (int i = 0; i < 15; i++)
		std::cout << "==";
	    std::cout << std::endl;

	setCursor(62, 1);

	std::cout << "MINESWEEPER";

	setCursor(52, 2);

	for (int i = 0; i < 15; i++)
		std::cout << "==";
}



