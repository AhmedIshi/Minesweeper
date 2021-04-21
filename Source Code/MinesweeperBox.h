#include "Box.h"

#include  "BoxStatus.h"

class MinesweeperBox : public Box
{
private:

	BoxStatus boxStatus;
	int adjacentMines;
    bool mineStatus;

public:

	void show() {};
	MinesweeperBox();
	void setMineStatus(bool);
	bool getMineStatus();
	void setAdjacentMines(int);
	int  getAdjacentMines();
	void setBoxStatus(BoxStatus);
	BoxStatus getBoxStatus();


};
