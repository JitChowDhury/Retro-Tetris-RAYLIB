#include "game.h"
#include <random>
#include <iostream>

/*
* Constructor initializes the grid, loads sounds, and starts background music.
*/
Game::Game()
{
	grid = Grid();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	gameOver = false;
	score = 0;

	InitAudioDevice();
	music = LoadMusicStream("assets/sounds/country.mp3");
	PlayMusicStream(music);
	rotateSound = LoadSound("assets/sounds/sound.wav");
	clearSound = LoadSound("assets/sounds/clear.mp3");
	std::cout << "Rotate Sound loaded: " << (rotateSound.stream.buffer != NULL) << std::endl;
	std::cout << "Clear Sound loaded: " << (clearSound.stream.buffer != NULL) << std::endl;


}

/*
*  Destructor unloads sounds and music from memory
*/

Game::~Game()
{
	UnloadSound(rotateSound);
	UnloadSound(clearSound);
	UnloadMusicStream(music);
	//CloseAudioDevice();
}
/**
 *Returns a random block and removes it from the pool .
 */
Block Game::GetRandomBlock()
{
	if (blocks.empty())
	{
		blocks=GetAllBlocks();
	}
	int randomIndex = rand() % blocks.size();
	Block block = blocks[randomIndex];
	blocks.erase(blocks.begin() + randomIndex);
	return block;
}
/*
*  Returns a vector containing all seven block types.
*/
std::vector<Block> Game::GetAllBlocks()
{
	return { IBlock(),JBlock(),LBlock(),OBlock(),SBlock(),TBlock(),ZBlock() };
}

/*
* Draws the grid, current falling block, and next block preview.
*/
void Game::Draw()
{
	grid.Draw();
	currentBlock.Draw(11,11);
	switch (nextBlock.id)
	{
	case 3:
		nextBlock.Draw(255, 290);
		break;
	case 4:
		nextBlock.Draw(255, 280);
		break;
	default:
		nextBlock.Draw(270, 270);
		break;
	}
}
/*
* Handles keyboard inputs (A/D/S/W) and restart logic.
*/
void Game::HandleInput()
{
	int keyPressed = GetKeyPressed();
	if (gameOver && keyPressed != 0)
	{
		gameOver = false;
		Reset();
	}
	switch (keyPressed)
	{
	case KEY_A:
		MoveBlockLeft();
		break;
	case KEY_D:
		MoveBlockRight();
		break;
	case KEY_S:
		MoveBlockDown();
		UpdateScore(0, 1);
		break;
	case KEY_W:
		RotateBlock();
		break;
	}
}
/*
* Moves the block left if it remains inside and fits.
*/
void Game::MoveBlockLeft()
{
	if (!gameOver)
	{
		currentBlock.Move(0, -1);
		if (IsBlockOutside() || !BlockFits())
		{
			currentBlock.Move(0, 1);
		}
	}
}
/*
* Moves the block right if it remains inside and fits.
*/
void Game::MoveBlockRight()
{
	if (!gameOver)
	{
		currentBlock.Move(0, 1);
		if (IsBlockOutside() || !BlockFits())
		{
			currentBlock.Move(0, -1);
		}
	}
}

void Game::MoveBlockDown()
{
	if (!gameOver)
	{
		currentBlock.Move(1, 0);
		if (IsBlockOutside() || !BlockFits())
		{
			currentBlock.Move(-1, 0);
			LockBlock();
		}
	}

}
/*
* Checks if any tile of the current block is outside the grid.
*/

bool Game::IsBlockOutside()
{
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles)
	{
		if (grid.isCellOutside(item.row, item.column))
		{
			return true;
		}
	}
	return false;
}
/*
* Rotates the block and reverts if rotation causes invalid placement.
*/
void Game::RotateBlock()
{
	if (!gameOver) {
		currentBlock.Rotate();
		if (IsBlockOutside() || !BlockFits())
		{
			currentBlock.UndoRotation();
		}
		else
		{
			PlaySound(rotateSound);
		}
	}

}
/*
* Locks the current block into the grid, checks for cleared rows, and spawns the next block.
*/
void Game::LockBlock()
{
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles)
	{
		grid.grid[item.row][item.column] = currentBlock.id;
	}

	currentBlock = nextBlock;
	nextBlock = GetRandomBlock();
	if (BlockFits() == false)
	{
		gameOver = true;
	}
	int rowsCleared=grid.ClearFullRows();
	if (rowsCleared > 0)
	{
	PlaySound(clearSound);
	UpdateScore(rowsCleared, 0);
	}
}
/*
* Checks if the current block can fit in its position without collision.
*/
bool Game::BlockFits()
{
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles)
	{
		if (!grid.isCellEmpty(item.row, item.column))
		{
			return false;
	    }
	}
	return true;
}

/*
* Resets the game to its initial state (used after game over).
*/

void Game::Reset()
{
	grid.Initialize();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	score = 0;
}
/*
* update player score
*/

void Game::UpdateScore(int linesCleared, int moveDownPoints)
{
	switch (linesCleared)
	{
	case 1:
		score += 100;
		break;
	case 2:
		score += 300;
		break;
	case 3:
		score += 500;
		break;
	default:
		break;
	}
	score += moveDownPoints;

}

