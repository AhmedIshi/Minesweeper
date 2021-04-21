class Box
{
protected:

	int rowNum;
	int columnNum;

public:

	Box();
	void isValid(int, int);
	void setRowNumber(int); 
	int  getRowNumber();
	void setColumnNumber(int);
	int  getColumnNumber();
	virtual void show() = 0;


};
