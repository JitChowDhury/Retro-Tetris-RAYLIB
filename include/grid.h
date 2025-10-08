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
	std::vector<Color> GetCellColors();


public:
	int grid[20][10];

	Grid();
	void Initialize();
	void Print();
	void Draw();
};