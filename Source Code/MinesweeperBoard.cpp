#include "MinesweeperBoard.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <windows.h>
#include <string>
#include <ctime>
#include <sstream>


using namespace std;

MinesweeperBoard::MinesweeperBoard(int totalRows, int totalColumns, int totalMines) : Board(totalRows, totalColumns)
{
	int count = totalMines;
	this->totalMines = totalMines;

	srand(time(NULL));

	// Allocation of board
	board = NULL;
	board = new MinesweeperBox * [totalRows];

	for (int i = 0; i < totalRows; ++i)
		board[i] = new MinesweeperBox[totalColumns];

	// Intiallization of board
	assignMineStatus();
	for (int i = 0; i < totalRows; ++i)
	{
		for (int j = 0; j < totalColumns; ++j)
		{
			board[i][j].setRowNumber(i);
			board[i][j].setColumnNumber(j);
			calculateAdjacentMines(i, j);
			
		}
	}	

}

void MinesweeperBoard::assignMineStatus(void)
{
	int flag = totalMines;
	int randomNumber = 0;
	int count = 0;

	for (int i = 0; i < totalRows; i++)
	{
		for (int j = 0; j < totalColumns; j++)
		{
			randomNumber = rand() % 10 ;

			if (randomNumber < 1 && flag > 0)
			{
				board[i][j].setMineStatus(true);
				++count;
				flag--;
			}
			else
				board[i][j].setMineStatus(false);
		}
	}

	if (count != totalMines)
		assignMineStatus();
	
}
	
Screen MinesweeperBoard::getScreen()
{
	return screen;
}

void MinesweeperBoard::exploreBoxes(int rowNum, int columnNum)
{
	if (!isValid(rowNum, columnNum))
		return;

	if (board[rowNum][columnNum].getAdjacentMines() > 0 && board[rowNum][columnNum].getBoxStatus() == unopened)
	{
		board[rowNum][columnNum].setBoxStatus(opened);
		return;
	}


	if (board[rowNum][columnNum].getAdjacentMines() == 0 && board[rowNum][columnNum].getBoxStatus() == unopened)
	{
		board[rowNum][columnNum].setBoxStatus(opened);

		exploreBoxes(rowNum - 1, columnNum - 1);
		exploreBoxes(rowNum - 1, columnNum);
		exploreBoxes(rowNum - 1, columnNum + 1);

		exploreBoxes(rowNum, columnNum - 1);
		exploreBoxes(rowNum, columnNum + 1);

		exploreBoxes(rowNum + 1, columnNum - 1);
		exploreBoxes(rowNum + 1, columnNum);
		exploreBoxes(rowNum + 1, columnNum + 1);

	}
}

bool MinesweeperBoard::click()
{
	//string line, intermediate;
	int rowNum = NULL, columnNum = NULL;
	char choice = NULL;
	bool temp = NULL;

	//getline(cin, line);

	//vector <string> tokens;
 //
	//stringstream check1(line);


	//while (getline(check1, intermediate, ' '))   // Tokenizing w.r.t. space ' ' 
	//{
	//	tokens.push_back(intermediate);
	//}

	//
	//stringstream temp(tokens[0]);
	//stringstream temp1(tokens[1]);
	//stringstream temp2(tokens[2]);

	//temp  >> choice;
	//temp1 >> rowNum;
	//temp2 >> columnNum;
	
	do
	{
		int rowNum1 = NULL, columnNum1 = NULL;
		char choice1 = NULL;
		bool temp1 = NULL;
		cout << "Enter M(move),F(flag),U(unflag) then coordinates: M/F/U Row Column:  ";
		cin >> choice >> rowNum >> columnNum;


		if (!isValid(rowNum, columnNum))
		{
			//you entered invalid coordinates. Try Again!
			MessageBox(NULL, TEXT("Try Again!! invalid coordinates. "), TEXT("Minesweeper"), MB_OK | MB_ICONQUESTION);
			continue;
		}
		temp = false;

	} while (temp);

	switch(choice)
	{
	case 'F': case 'f':

		if (board[rowNum][columnNum].getBoxStatus() != flag && board[rowNum][columnNum].getBoxStatus() != opened)
			board[rowNum][columnNum].setBoxStatus(flag);
		else
			// print : Box is already flagged/opened
			MessageBox(NULL, TEXT("Box is already flagged/opened"), TEXT("Minesweeper"), MB_OK | MB_ICONQUESTION);
			
			break;

	case 'U': case 'u':

		if (board[rowNum][columnNum].getBoxStatus() == flag)
			board[rowNum][columnNum].setBoxStatus(unopened);
		else
			// box is already unflagged
			MessageBox(NULL, TEXT("Box is already unflagged "), TEXT("Minesweeper"), MB_OK | MB_ICONQUESTION);
			break;

	case 'M': case 'm':

		if (board[rowNum][columnNum].getBoxStatus() == unopened)
		{

			

			if (board[rowNum][columnNum].getMineStatus() == true)
				return true;

			if (board[rowNum][columnNum].getAdjacentMines() == 0)
				exploreBoxes(rowNum, columnNum);
			else 
				board[rowNum][columnNum].setBoxStatus(opened);
		}
		else
			// print: box is already opened/flagged
			MessageBox(NULL, TEXT("Box is already opened/flagged."), TEXT("Minesweeper"), MB_OK | MB_ICONQUESTION);

			break;
	default:
		   // invalid input try again;
		MessageBox(NULL, TEXT("invalid input try Again."), TEXT("Minesweeper"), MB_OK | MB_ICONQUESTION);
		
	}
	return false;
}

void MinesweeperBoard::calculateAdjacentMines( int rowNum, int columnNum)
{
	int adjacentMines = 0;

	if (isValid(rowNum-1, columnNum-1) && this->board[rowNum-1][columnNum-1].getMineStatus())
		adjacentMines++;
	if (isValid(rowNum-1, columnNum) && this->board[rowNum-1][columnNum].getMineStatus())
		adjacentMines++;
	if (isValid(rowNum-1, columnNum+1) && this->board[rowNum-1][columnNum+1].getMineStatus())
		adjacentMines++;
	if (isValid(rowNum, columnNum-1) && this->board[rowNum][columnNum-1].getMineStatus())
		adjacentMines++;
	if (isValid(rowNum, columnNum+1) && this->board[rowNum][columnNum+1].getMineStatus())
		adjacentMines++;
	if (isValid(rowNum+1, columnNum-1) && this->board[rowNum+1][columnNum-1].getMineStatus())
		adjacentMines++;
	if (isValid(rowNum+1, columnNum) && this->board[rowNum+1][columnNum].getMineStatus())
		adjacentMines++;
	if (isValid(rowNum+1, columnNum+1) && this->board[rowNum+1][columnNum+1].getMineStatus())
		adjacentMines++;

	board[rowNum][columnNum].setAdjacentMines(adjacentMines);
	
		
}

int MinesweeperBoard::countUnopenedBoxes()
{
	int count = 0;

	for (int i = 0; i < this->totalRows; ++i)
	{
		for (int j = 0; j < this->totalColumns; ++j)
		{
			if (board[i][j].getBoxStatus() == unopened || board[i][j].getBoxStatus() == flag )
				count++;
		}
	}

	return count;
}

void MinesweeperBoard::printBoard(void)
{

	int count = 0;
	int p = 46;
	int q = 7;

	screen.minesweeperLogo();
	screen.printInfo();

	for (int i = 0; i < this->totalRows; ++i)
	{
		for (int j = 0; j < this->totalColumns; ++j)
		{
			if (board[i][j].getBoxStatus() == flag)
				count++;
		}
	}

	screen.setCursor(2, 10);
	std::cout << "Mines Left: " << (totalMines - count);


	for (int i = 0; i < totalRows; ++i)
	{
		screen.setCursor(p, q);
		q = q + 2;
		for (int j = 0; j < totalColumns; ++j)
		{
			
			if (board[i][j].getBoxStatus() == flag)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				std::cout << "F" << "    ";
			}
			else if (board[i][j].getBoxStatus() == unopened)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				std::cout << "+" << "    ";
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				std::cout << board[i][j].getAdjacentMines() << "    ";
			}
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
	//for the purpose of showing side rows and columns
	p = 42;
	q = 5;

	for (int i = 0; i < totalRows; ++i )
	{
		screen.setCursor(p, q);
		q = q + 2;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

		for(int j = 0; j < totalRows; j++)
		{
			
			if (i == 0)
				std::cout << "    " << j;
		}

		std::cout << std::endl;
		screen.setCursor(p, q);
		std::cout << i << "|";
		std::cout << std::endl;
	
	}	
	std::cout << std::endl;
}

void MinesweeperBoard::printFinalBoard(void)
{
	int count = 0;
	int p = 46;
	int q = 7;

	screen.minesweeperLogo();
	screen.printInfo();
	

	for (int i = 0; i < this->totalRows; ++i)
	{
		for (int j = 0; j < this->totalColumns; ++j)
		{
			if (board[i][j].getBoxStatus() == flag)
				count++;
		}
	}

	screen.setCursor(2, 10);
	std::cout << "Mines Left: " << (totalMines - count);

	for (int i = 0; i < totalRows; ++i)
	{
		screen.setCursor(p, q);
		q = q + 2;
		for (int j = 0; j < totalColumns; ++j)
		{

			if (board[i][j].getMineStatus())
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				std::cout << "*" << "    ";
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				std::cout << board[i][j].getAdjacentMines() << "    ";
			}
		}
		std::cout << std::endl;
		
	}
	//for the purpose of showing side rows and columns
	p = 42;
	q = 5;

	for (int i = 0; i < totalRows; ++i)
	{
		screen.setCursor(p, q);
		q = q + 2;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

		for (int j = 0; j < totalRows; j++)
		{

			if (i == 0)
				std::cout << "    " << j;
		}

		std::cout << std::endl;
		screen.setCursor(p, q);
		std::cout << i << "|";
		std::cout << std::endl;
		std::cout << std::endl;
	}



}

MinesweeperBoard::~MinesweeperBoard()
{
	for (int i = 0; i < totalRows; ++i)
		delete[] board[i];
	delete[] board;
}
