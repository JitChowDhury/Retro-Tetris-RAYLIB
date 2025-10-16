#include <raylib.h>
#include <ctime>
#include "game.h"
int main()
{
	srand(time(0));
	Color darkBlue = { 44,44,127,255 };
	InitWindow(300, 600, "Tetris");
	SetTargetFPS(60);
	Game game = Game();

	while (!WindowShouldClose())
	{
		game.HandleInput();
		BeginDrawing();
		ClearBackground(darkBlue);  
		game.Draw();
		EndDrawing();
	}

	CloseWindow();
}