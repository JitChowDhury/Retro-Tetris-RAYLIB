#include "block.h"

/*
* constructs the block object with default size rotationstate and color
*/

Block::Block()
{
	cellSize = 30;
	rotationState = 0;
	colors = GetCellColors();
	rowOffset = 0;
	columnOffset = 0;

}
/**
 * Draws the block’s current shape at the given offset.
 *
 * The function uses the current rotation state to get the block’s
 * cell positions, then draws each tile using its assigned color.
 *
 *  offsetX The X offset (in pixels) for drawing on the screen.
 *  offsetY The Y offset (in pixels) for drawing on the screen.
 */
void Block::Draw(int offsetX , int offsetY)
{
	// Get current rotation shape
	std::vector<Position> tiles = GetCellPositions();
	for (Position item : tiles)
	{
		// Draw each tile at its grid position using the block’s color
		DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
	}
}

/*
 * Moves the block by adjusting its row and column offset.
 *
 *  param:Number of rows to move vertically , Number of columns to move horizontally.
 */

void Block::Move(int rows,int columns)
{
	rowOffset += rows;
	columnOffset += columns;
}

/*
* Returns the blocks tile positions considering its current offset
* 
* each tiles position is calculated by adding the blocks current row and column offset to its base rotation state
* 
* return:Vector if position objects representing each occupied cell on the grid
*/

std::vector<Position> Block::GetCellPositions()
{
	std::vector<Position> tiles = cells[rotationState];
	std::vector<Position> movedTiles;

	for (Position item : tiles)
	{
		Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
		movedTiles.push_back(newPos);
	}
	return movedTiles;
}

/*
* Rotates the block clockwise to the next rotation state.
* 
* when the rotation index reaches last it loops back to 0
*/

void Block::Rotate()
{
	rotationState++;
	if (rotationState == (int)cells.size())
	{
		rotationState = 0;
	}
}

/*
 * Rotates the block counter-clockwise (undoes the last rotation).
 *
 * If the rotation index becomes negative, it loops back to the last rotation state.
 */
void Block::UndoRotation()
{
	rotationState--;
	if (rotationState == -1)
	{
		rotationState = (int)cells.size() - 1;
	}
}
