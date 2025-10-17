#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game
{
private:
	std::vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;
	bool IsBlockOutside();
	void RotateBlock();
	void LockBlock();
	bool BlockFits();
	void Reset();
public:
	Game();
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	void Draw();
	void HandleInput();
	void MoveBlockLeft();
	void MoveBlockRight();
	void MoveBlockDown();
	Grid grid;
	bool gameOver;


};