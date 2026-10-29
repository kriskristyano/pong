#include "raylib.h"
#include <stdio.h>

int main(void) {
    
    // Screen settings
    const int SCREEN_WIDTH = 1200;
    const int SCREEN_HEIGHT = 900;
    const int PADDING = 10;

    // Ball settings
    const Color BALL_COLOR = RAYWHITE;
    const int BALL_SIZE = 25;
    const int BALL_SPEED = 10;

    int ball_speed_x = BALL_SPEED;
    int ball_speed_y = BALL_SPEED;

    int ball_x = SCREEN_WIDTH/2 - BALL_SIZE/2;
    int ball_y = SCREEN_HEIGHT/2 - BALL_SIZE/2;

    // Paddle settings
    const Color PADDLE_COLOR = BALL_COLOR;
    const int PADDLE_WIDTH = SCREEN_WIDTH/75;
    const int PADDLE_HEIGHT = PADDLE_WIDTH*8;

    // Left paddle settings
    int left_paddle_x = PADDING;
    int left_paddle_y = .5*SCREEN_HEIGHT - PADDLE_HEIGHT/2;

    // Right paddle settings
    int right_paddle_x = SCREEN_WIDTH - PADDING - PADDLE_WIDTH;
    int right_paddle_y = left_paddle_y;

    bool is_two_player = 0;

    int score = 0;

    int digits[10][7][5] = {
        {
            { 0, 1, 1, 1, 0 },
            { 1, 0, 0, 0, 1 },
            { 1, 0, 0, 0, 1 },
            { 1, 0, 0, 0, 1 },
            { 1, 0, 0, 0, 1 },
            { 1, 0, 0, 0, 1 },
            { 0, 1, 1, 1, 0 }
        },
        {
            { 0, 0, 0, 0, 1 },
            { 0, 0, 0, 0, 1 },
            { 0, 0, 0, 0, 1 },
            { 0, 0, 0, 0, 1 },
            { 0, 0, 0, 0, 1 },
            { 0, 0, 0, 0, 1 },
            { 0, 0, 0, 0, 1 }
        },
        {
            { 1, 1, 1, 1, 1 },
            { 0, 0, 0, 0, 1 },
            { 0, 0, 0, 0, 1 },
            { 1, 1, 1, 1, 1 },
            { 1, 0, 0, 0, 0 },
            { 1, 0, 0, 0, 0 },
            { 1, 1, 1, 1, 1 }
        },
        {
            { 1, 1, 1, 1, 1 },
            { 0, 0, 0, 0, 1 },
            { 0, 0, 0, 0, 1 },
            { 1, 1, 1, 1, 1 },
            { 0, 0, 0, 0, 1 },
            { 0, 0, 0, 0, 1 },
            { 1, 1, 1, 1, 1 }
        },
        {
            { 1, 0, 0, 0, 1 },
            { 1, 0, 0, 0, 1 },
            { 1, 0, 0, 0, 1 },
            { 1, 1, 1, 1, 1 },
            { 0, 0, 0, 0, 1 },
            { 0, 0, 0, 0, 1 },
            { 0, 0, 0, 0, 1 }
        },
        {
            { 1, 1, 1, 1, 1 },
            { 1, 0, 0, 0, 0 },
            { 1, 0, 0, 0, 0 },
            { 1, 1, 1, 1, 1 },
            { 0, 0, 0, 0, 1 },
            { 0, 0, 0, 0, 1 },
            { 1, 1, 1, 1, 1 }
        },
        {
            { 1, 1, 1, 1, 1 },
            { 1, 0, 0, 0, 0 },
            { 1, 0, 0, 0, 0 },
            { 1, 1, 1, 1, 1 },
            { 1, 0, 0, 0, 1 },
            { 1, 0, 0, 0, 1 },
            { 1, 1, 1, 1, 1 }
        },
        
        {
            { 1, 1, 1, 1, 1 },
            { 0, 0, 0, 0, 1 },
            { 0, 0, 0, 0, 1 },
            { 0, 0, 0, 0, 1 },
            { 0, 0, 0, 0, 1 },
            { 0, 0, 0, 0, 1 },
            { 0, 0, 0, 0, 1 }
        },
        {
            { 1, 1, 1, 1, 1 },
            { 1, 0, 0, 0, 1 },
            { 1, 0, 0, 0, 1 },
            { 1, 1, 1, 1, 1 },
            { 1, 0, 0, 0, 1 },
            { 1, 0, 0, 0, 1 },
            { 1, 1, 1, 1, 1 }
        },
        {
            { 1, 1, 1, 1, 1 },
            { 1, 0, 0, 0, 1 },
            { 1, 0, 0, 0, 1 },
            { 1, 1, 1, 1, 1 },
            { 0, 0, 0, 0, 1 },
            { 0, 0, 0, 0, 1 },
            { 0, 0, 0, 0, 1 }
        }
    };

    // Initialize
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "rectangles");

    SetTargetFPS(60);

    
    while (!WindowShouldClose()) {

            // Ball collision
            int new_x = ball_x + ball_speed_x;
            int new_y = ball_y + ball_speed_y;
            bool is_left_paddle_collision = new_y >= left_paddle_y && new_y <= left_paddle_y + PADDLE_HEIGHT && new_x <= left_paddle_x + PADDLE_WIDTH;
            bool is_right_paddle_collision =  new_y >= right_paddle_y && new_y <= right_paddle_y + PADDLE_HEIGHT && new_x + BALL_SIZE >= right_paddle_x;

            if (new_x + BALL_SIZE >= SCREEN_WIDTH || new_x <= 0 || is_left_paddle_collision || is_right_paddle_collision) {
               if (is_left_paddle_collision) {
                   score += 1;
               }
               ball_speed_x *= -1;
            }

            if (new_y + BALL_SIZE >= SCREEN_HEIGHT || new_y <= 0) {
               ball_speed_y *= -1;
            }

            ball_x += ball_speed_x;
            ball_y += ball_speed_y;

            // Input management
            if (IsKeyDown(KEY_S) && (left_paddle_y + PADDLE_HEIGHT + PADDING <= SCREEN_HEIGHT)) {
                left_paddle_y += BALL_SPEED;
            }

            if (IsKeyDown(KEY_W) && (left_paddle_y >= PADDING)) {
                left_paddle_y -= BALL_SPEED;
            }

            if (is_two_player) {
                if (IsKeyDown(KEY_DOWN) && (right_paddle_y + PADDLE_HEIGHT + PADDING <= SCREEN_HEIGHT)) {
                    right_paddle_y += BALL_SPEED;
                }

                if (IsKeyDown(KEY_UP) && (right_paddle_y >= PADDING)) {
                    right_paddle_y -= BALL_SPEED;
                }
            }
            else {
                int new_right_paddle_y = ball_y - PADDLE_HEIGHT/2;
                if (new_right_paddle_y >= 0 && new_right_paddle_y + PADDLE_HEIGHT <= SCREEN_HEIGHT) right_paddle_y = new_right_paddle_y;
            }

            // Points 
            void render_number(int num[7][5]) {
                for (int row = 0; row < 7; row++) {
                    for (int col = 0; col < 5; col++) {
                        if (num[row][col]) {
                            DrawRectangle(col*BALL_SIZE + SCREEN_WIDTH/2 - BALL_SIZE*5 - 2*PADDING,row*BALL_SIZE + 2*PADDING,BALL_SIZE,BALL_SIZE,RAYWHITE);
                        }
                    }
                }
            }

        BeginDrawing();

            ClearBackground(BLACK);

            DrawLineDashed((Vector2){ SCREEN_WIDTH/2    , 0 }, (Vector2) { SCREEN_WIDTH/2    , SCREEN_HEIGHT }, BALL_SIZE, BALL_SIZE+1, BALL_COLOR);
            DrawLineDashed((Vector2){ SCREEN_WIDTH/2 + 1, 0 }, (Vector2) { SCREEN_WIDTH/2 + 1, SCREEN_HEIGHT }, BALL_SIZE, BALL_SIZE+1, BALL_COLOR);
            DrawLineDashed((Vector2){ SCREEN_WIDTH/2 - 1, 0 }, (Vector2) { SCREEN_WIDTH/2 - 1, SCREEN_HEIGHT }, BALL_SIZE, BALL_SIZE+1, BALL_COLOR);

            // Ball
            DrawRectangle(ball_x, ball_y, BALL_SIZE, BALL_SIZE, BALL_COLOR);

            // Points
            render_number(digits[score]);

            // Left paddle
            DrawRectangle(left_paddle_x, left_paddle_y, PADDLE_WIDTH, PADDLE_HEIGHT, PADDLE_COLOR);

            // Right paddle
            DrawRectangle(right_paddle_x, right_paddle_y, PADDLE_WIDTH, PADDLE_HEIGHT, PADDLE_COLOR);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
