/**
  This file defines how the grid is initialized drawn on screen, and updated
  when rows are completed or cleared. It provides basic functions such as
  checking cell boundaries, clearing full rows, and moving rows down.
 */

#include "grid.h"
#include <iostream>
#include <colors.h>

//costructs the grid with fixed number of cells and columns

Grid::Grid():numRows(20),numCols(10),cellSize(30)
{
	Initialize();
	colors = GetCellColors();
}

//initialize all grid with 0s i.e empty cells
void Grid::Initialize()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numCols; column++)
		{
			grid[row][column] = 0;
		}
	}
}
//prints the grid to terminal
void Grid::Print()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numCols; column++)
		{
			std::cout<<grid[row][column]<<" ";
		}
		std::cout << std::endl;
	}
}
//draw on window
void Grid::Draw()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numCols; column++)
		{
			int cellValue = grid[row][column];
			DrawRectangle(column * cellSize+11, row * cellSize+11, cellSize-1, cellSize-1, colors[cellValue]);
		}
		
	}
}

/*
* Checks if the cell is outside or not
*/

bool Grid::isCellOutside(int row, int column)
{
	if (row >= 0 && row < numRows && column >= 0 && column < numCols)
	{
	   return false;
	}
	return true;
}
/*
* Checks if the cell if empty
*/
bool Grid::isCellEmpty(int row, int column)
{
	if (grid[row][column] == 0)
	{
		return true;
	}
	return false;
}
/*
* clear rows and return number of rows cleared
*/

int Grid::ClearFullRows()
{
	int completed = 0;
	//traverse from bottom to top for proper shifting
	for (int row = numRows - 1; row >= 0; row--)
	{
		if (IsRowFull(row))
		{
			ClearRow(row);
			completed++;
		}
		else if(completed>0)
		{
			MoveRowDown(row, completed);
		}
	}
	return completed;

}

/*
* Checks if the given row is completely filled or not 
* return: true if filled else false
*/
bool Grid::IsRowFull(int row)
{
	for (int column = 0; column < numCols; column++)
	{
		if (grid[row][column] == 0)
		{
			return false;
		}
	}
	return true;
}

/*
* Clear the given row
*/

void Grid::ClearRow(int row)
{
	for (int column = 0; column < numCols; column++)
	{
		grid[row][column] = 0;
	}
}
/*
* Moves the row down by numrows
*/
void Grid::MoveRowDown(int row, int numRows)
{
	//loops through all the columns
	for (int column = 0; column < numCols; column++)
	{
		//copies value from row col to row+numrow below it
		grid[row + numRows][column] = grid[row][column];
		grid[row][column] = 0;
	}

}




