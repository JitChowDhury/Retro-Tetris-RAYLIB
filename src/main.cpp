#include <raylib.h>


int main()
{
	int ballX = 400;
	int ballY = 400;
	Color green = { 20,160,133,255 };

	InitWindow(800, 800, "First Game");
	SetTargetFPS(60);
	//GameLoop

	while (!WindowShouldClose())
	{
        //1 . Event Handling
		if (IsKeyDown(KEY_D))
		{
			ballX += 3;
		}
		else if (IsKeyDown(KEY_A))
		{
			ballX -= 3;
		}
		else if (IsKeyDown(KEY_W))
		{
			ballY -= 3;
		}
		else if (IsKeyDown(KEY_S))
		{
			ballY += 3;
		}
        //2 . Updating Position

		//ballX += 3;
        
		//1 . Drawing
		BeginDrawing();
		ClearBackground(green);
		DrawCircle(ballX, ballY, 20, WHITE);
		EndDrawing();



	}


	CloseWindow();
	return 0;
}