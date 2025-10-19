/*
* Main Controller for the game
* Manages all game elements , including the grid,block
* 
* 
* Manages all game elements including the grid blocks and input handling scoring sounds 
* 
*/

#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game
{
private:
	//container for all 7 block types ( I , J, , L , 0 , S , T , Z)
	std::vector<Block> blocks;       
	//The currently falling block
	Block currentBlock;
	//The next block
	Block nextBlock;
	//The Game grid
	Grid grid;
	//block rotate sound
	Sound rotateSound;
	//block clear sound
	Sound clearSound;

	//checks if the block is outside the grid boundaries
	bool IsBlockOutside();
	//rotates the current block if possible
	void RotateBlock();
	//lock the current block it lands
	void LockBlock();
	//check if the block fits in its current position
	bool BlockFits();
	//reset the game state to start a new game
	void Reset();
	//Updateds score based on game actions
	void UpdateScore(int linesCleared,int moveDownPoints);
	//Retruns a random block and removes it from the block pool
	Block GetRandomBlock();
	//returns a list of all block types
	std::vector<Block> GetAllBlocks();
	//Moves block left if possible
	void MoveBlockLeft();
	//Moves block right if possible
	void MoveBlockRight();

public:
	//flag to track if the game has ended or not
	bool gameOver;
	//players current score
	int score;
	//bg music
	Music music;

	//Intializes game and load assets
	Game();
	//destructor cleans up loaded sounds and music
	~Game();
	//draws the grid current block and next block
	void Draw();
	//Handles keyboard input
	void HandleInput();
	//Moves block down one step
	void MoveBlockDown();



};