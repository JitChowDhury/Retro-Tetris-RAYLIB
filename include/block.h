/*
* The block class manages the behaviour of an individual block
* including its position rotation movement and rendering on the grid
* Each block contains a set of rotation states defined by cell position
*/



#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

/*
* Each block contains multiple rotation states stored as vectors of position objects
* The class handles drawing movemnt and rotation logic used in block based puzzle games
*/
class Block
{
private:
	int cellSize;                                //size of each block cell in pixels
	int rotationState;                           //current rotation index of the block
	std::vector<Color> colors;                   //List of available colors
	int rowOffset;                               //current row offset of the block on the grid
	int columnOffset;                            //current column offset of the block on the grid
public:
	int id;                                      //Unique ID representing the block type(used for color selection)
	std::map<int, std::vector<Position>> cells;  //Map of rotation states ( key=rotation index , value = list of cell position)
	Block();                                     //Constructor : constructs a new block with default size and rotation
	void Draw(int offsetX , int offsetY);        //Draws the block on game window
	void Move(int rows,int columns);             //Move the block by given number of rows and columns
	std::vector<Position> GetCellPositions();    //return the vector of position object representing the cells location
	void Rotate();                               //rotates the block clockwise to the next rotaion state
	void UndoRotation();                         //undoes the last rotation ( counter clockwise)
};