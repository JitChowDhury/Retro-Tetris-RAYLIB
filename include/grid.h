
/*
* The grid class represents a 2d grid that manages the game play area
* it provides functions to initialize , draw and update the grid
* and also clearing rows checking boundaries amnd handling movement
*/

#pragma once
#include <vector>
#include <raylib.h>


class Grid
{
private:
	int numRows; //Total number of row
	int numCols; //Total number of columns
	int cellSize; //size of a individual cell in pixel
	std::vector<Color> colors; //a vector of colors 
/*
* 	check whether a specific row is completely filled. 
*   param: the row index
*   return : true if full else false
*/

	bool IsRowFull(int row);
   /*
    * clears all cells in a given row by setting them to zero
    * param: the row index to clear
    */

	void ClearRow(int row);

	/*
	* Moves a row down by a given number of rows
	* param: the row index tto move and column : number of rows to move down
	*/

	void MoveRowDown(int row, int column);




public:
	//2d array representing the grid cells (0=empry >0 : occupied)
	int grid[20][10];
	//constructs the grid object
	Grid(); 
	// Initialize the grid with zeros
	void Initialize();
	// initialize the grid
	void Print(); 
	// draws the grid on window
	void Draw();

	/*
	* Checks whether a given cell is outside the grid boundaries
	* param:row and column
	* return :true if cell is outside else false
	*/
	bool isCellOutside(int row, int column);

	/*
	* Checks if the given cell is empty
	* param: row and column
	* return: if the cell is empty return true else false
	*/

	bool isCellEmpty(int row, int column);
	/*
     * Clears all full rows in the grid and shift remaining rows downward.
     * return the numbers of row  cleard
     */
	int ClearFullRows();

};