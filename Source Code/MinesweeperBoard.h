#include "Board.h"
#include "MinesweeperBox.h"
#include "Score.h"
#include  "Screen.h"

class MinesweeperBoard : public Board 
{
private:

	int totalMines;
	MinesweeperBox** board;
	Screen screen;
	Score score;

	void exploreBoxes(int, int);
	void assignMineStatus(void);
	void calculateAdjacentMines(int, int);

public:

	void show() {};
	MinesweeperBoard(int, int, int);
	int  countUnopenedBoxes(void);
	void printBoard(void);
	void printFinalBoard(void);
	Screen getScreen();
	bool click();
	~MinesweeperBoard();

};