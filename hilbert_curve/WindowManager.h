#pragma once
#include <SDL.h>
#include <list>
#include <tuple>

#define RED 0xFF, 0x00, 0x00, 0xFF
#define BLUE 0x00, 0x00, 0xFF, 0xFF
#define GREEN 0x00, 0xFF, 0x00, 0xFF
#define YELLOW 0xFF, 0xFF, 0x00, 0xFF
#define PURPLE 0x55, 0x1A, 0x8B, 0xFF
#define BLACK 0x00, 0x00, 0x00, 0x00

class WindowManager
{
public:
    WindowManager();
    ~WindowManager();
    bool Init();
    void Close();
    bool Update(int reps);
private:

    void lineForward(int *x, int *y, int lengthX, int lengthY,
                     Uint8 R, Uint8 G, Uint8 B, Uint8 Alpha);

    void drawHilbert(int *x, int *y, int lengthX, int lengthY, int lvl);
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
};
