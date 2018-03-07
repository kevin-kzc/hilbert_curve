#include "WindowManager.h"
#include <iostream>
#include <sstream>
#include <string>
const int WINDOW_WIDTH = 1020;
const int WINDOW_HEIGHT = 800;

WindowManager::WindowManager()
{
    
}

WindowManager::~WindowManager()
{

}

bool WindowManager::Init()
{
    bool retVal = false;
    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
        window = SDL_CreateWindow("Hilbert curve ",
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  WINDOW_WIDTH,
                                  WINDOW_HEIGHT,
                                  SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED);
        if (window != nullptr)
        {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer != nullptr)
            {
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                retVal = true;
            }
        }
    }
    return retVal;
}

void WindowManager::Close()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = nullptr;
    SDL_Quit();
}

bool WindowManager::Update(int reps)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
    std::stringstream title;
    title << "Hilbert curve level: " << reps;
    SDL_SetWindowTitle(window, title.str().c_str());

    //Render white background
    SDL_Rect backgroundRect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &backgroundRect);
    int x = 1, y = 1, length = 100 / reps;
    
    drawHilbert(&x, &y, 0, length, reps);
    SDL_RenderPresent(renderer);
    return true;
}

void WindowManager::lineForward(int *x, int *y, int lengthX, int lengthY,
    Uint8 R, Uint8 G, Uint8 B, Uint8 Alpha) {
    SDL_SetRenderDrawColor(renderer, R, G, B, Alpha);
    SDL_RenderDrawLine(renderer, *x, *y, lengthX + *x, lengthY + *y);

    *x += lengthX;
    *y += lengthY;
}

void WindowManager::drawHilbert(int *x, int *y, int lengthX, int lengthY, int lvl) {
    if (lvl>0) {
        drawHilbert(x, y, -lengthY, -lengthX, lvl - 1);
        lineForward(x, y, -lengthX, lengthY, RED);
        drawHilbert(x, y, lengthX, lengthY, lvl - 1);
        lineForward(x, y, lengthY, -lengthX, BLUE);
        drawHilbert(x, y, lengthX, lengthY, lvl - 1);
        lineForward(x, y, lengthX, -lengthY, GREEN);
        drawHilbert(x, y, lengthY, lengthX, lvl - 1);
    }
}