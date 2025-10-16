#include <raylib.h>
#include <ctime>
#include "game.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}
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
		if (EventTriggered(0.3))
		{
		   game.MoveBlockDown();
		}
		BeginDrawing();
		ClearBackground(darkBlue);  
		game.Draw();
		EndDrawing();
	}

	CloseWindow();
}