#include "MinesweeperBoard.h"
#include <iomanip>
#include <iostream>
#include <windows.h>

using namespace std;



int main()
{
	char dummy;

	do
	{

		int choice;
		int rowNumber, columnNum;
		int totalMines;
		bool flag = false;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

		std::cout << "Enter the Difficulty Level" << std::endl;
		std::cout << "Press 1 for BEGINNER (10 * 10 Cells and 10 Mines)" << std::endl;
		std::cout << "Press 2 for INTERMEDIATE (12 * 12 Cells and 15 Mines)" << std::endl;
		std::cout << "Press 3 for ADVANCED (12 * 12 Cells and 20 Mines)" << std::endl;
		std::cin >> choice;

		switch(choice)
		{

		case 1:

			rowNumber = columnNum = 10;
			totalMines = 10;
			break;

		case 2:

			rowNumber = columnNum = 12;
			totalMines = 15;
			break;

		case 3:

			rowNumber = columnNum = 12;
			totalMines = 20;
			break;

		default:

			 	MessageBox(NULL, TEXT("Try Again! Invalid Choice "), TEXT("Minesweeper"), MB_OK | MB_ICONQUESTION);


		}
		
		if (choice == 1 || choice == 2 || choice == 3)
		{

			MinesweeperBoard minesweeper(rowNumber, columnNum, totalMines);
			minesweeper.getScreen().clearScreen();


			while (!flag)
			{

				
				minesweeper.printBoard();
				flag = minesweeper.click();
				minesweeper.getScreen().clearScreen();
				
				
				if (flag)
				{
					// message: you lose
					minesweeper.printFinalBoard();
					MessageBox(NULL, TEXT("Boom!! You lose "), TEXT("Minesweeper"), MB_OK | MB_ICONQUESTION);

				}
				else if (minesweeper.countUnopenedBoxes() == totalMines)
				{
					// message: you win
					// show final score here
					minesweeper.printFinalBoard();
					MessageBox(NULL, TEXT("Congratualtions!! You Win "), TEXT("Minesweeper"), MB_OK | MB_ICONQUESTION);
					break;
				}
			}

			minesweeper.getScreen().setCursor(2, 25);
		}

		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "if you want to play Again, Press Y or y : ";
		std::cin >> dummy;

	} while( dummy == 'y' || dummy == 'Y' );



	std::system("pause");
}


