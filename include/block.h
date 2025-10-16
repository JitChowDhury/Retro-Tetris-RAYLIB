#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"


class Block
{
private:
	int cellSize;
	int rotationState;
	std::vector<Color> colors;
	int rowOffset;
	int columnOffset;
public:
	Block();
	void Draw();
	void Move(int rows,int columns);
	int id;
	std::map<int, std::vector<Position>> cells;
	std::vector<Position> GetCellPositions();
	void Rotate();
	void UndoRotation();
};