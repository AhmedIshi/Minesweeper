class Board
{
protected:

	 int totalRows;
	 int totalColumns;

public:
	
	Board(int, int);
	bool isValid(int, int);
	virtual void show() = 0;

};
