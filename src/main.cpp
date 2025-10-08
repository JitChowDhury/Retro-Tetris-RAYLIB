#include <raylib.h>
#include "grid.h"

int main()
{
	Color darkBlue = { 44,44,127,255 };
	InitWindow(300, 600, "Tetris");
	SetTargetFPS(60);

	Grid grid = Grid();
	grid.grid[0][0] = 1;
	grid.grid[3][5] = 3;
	grid.grid[13][8] = 6;
	grid.Print();

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(darkBlue);  
		grid.Draw();

		EndDrawing();
	}

	CloseWindow();
}