#include "block.h"

Block::Block()
{
	cellSize = 30;
	rotationState = 0;
	colors = GetCellColors();
}

void Block::Draw()
{
	// Get current rotation shape
	std::vector<Position> tiles = cells[rotationState];
	for (Position item : tiles)
	{
		// Draw each tile at its grid position using the block’s color
		DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
	}
}
