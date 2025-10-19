#include <raylib.h>
#include <ctime>
#include "game.h"
#include "colors.h"
#include <iostream>

// Last time an interval event occurred
double lastUpdateTime = 0;

// Function to trigger events at a fixed interval 
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
    // Seed random number generator
    srand(time(0));


    // Initialize the game window
    InitWindow(500, 620, "Tetris");
    SetTargetFPS(60);

    // Load custom font
    Font font = LoadFontEx("assets/fonts/monogram.ttf", 64, 0, 0);

    // Create the game object
    Game game = Game();

    // Main game loop
    while (!WindowShouldClose())
    {
        // Keep music playing smoothly
        UpdateMusicStream(game.music);

        // Handle player input (movement, rotation, restart)
        game.HandleInput();

        // Drop block automatically every 0.3 seconds
        if (EventTriggered(0.3))
        {
            game.MoveBlockDown();
        }

        // Start drawing
        BeginDrawing();

        // Clear the screen with dark blue background
        ClearBackground(darkBlue);

        // Draw UI labels
        DrawTextEx(font, "Score", { 365,15 }, 38, 2, WHITE);
        DrawTextEx(font, "Next", { 370,175 }, 38, 2, WHITE);

        // Show game over message if the game has ended
        if (game.gameOver)
        {
            DrawTextEx(font, "GAME OVER!!", { 320,450 }, 38, 2, WHITE);
        }

        // Draw score background rectangle
        DrawRectangleRounded({ 320,55,170,60 }, 0.3, 6, lightBlue);

        // Convert score integer to string for drawing
        char scoreText[10];
        sprintf(scoreText, "%d", game.score);

        // Measure the width of the score text to center it
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        // Draw score text centered inside the rectangle
        DrawTextEx(font, scoreText, { 320 + (170 - textSize.x) / 2, 65 }, 38, 2, WHITE);

        // Draw next block preview rectangle
        DrawRectangleRounded({ 320,215,170,180 }, 0.3, 6, lightBlue);

        // Draw the grid and blocks
        game.Draw();

        // Finish drawing for this frame
        EndDrawing();
    }

    // Close audio and window when game ends
    CloseAudioDevice();
    CloseWindow();
}
