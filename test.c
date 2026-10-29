#include <stdio.h>
#include "raylib.h"

int main(void) {

    const int SCREEN_WIDTH = 1200;
    const int SCREEN_HEIGHT = 900;
    const int BALL_SIZE = 20;

    int one[][4] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };
    

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "test");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

            for (int row = 0; row < 7; row++) {
                for (int col = 0; col < 4; col++) {
                    if (one[row][col]) {
                        DrawRectangle(col*BALL_SIZE,row*BALL_SIZE,BALL_SIZE,BALL_SIZE,RAYWHITE);
                    }
                }
            }

        EndDrawing();
    }

    return 0;
}
