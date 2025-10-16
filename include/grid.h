#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
private:
	int numRows;
	int numCols;
	int cellSize;
	std::vector<Color> colors;



public:
	int grid[20][10];

	Grid();
	void Initialize();
	void Print();
	void Draw();
	bool isCellOutside(int row, int column);
	bool isCellEmpty(int row, int column);

};