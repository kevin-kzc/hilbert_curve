#include "WindowManager.h"
#undef main
#include <iostream>
int main(int argc, char* argv[])
{
    WindowManager* windowManager = new WindowManager();
    SDL_mutex* mutex = SDL_CreateMutex();
    if (windowManager->Init())
    {
        bool quit = false;
        int lvl = 0;
        SDL_Event e;
        while (!quit)
        {
            if (SDL_LockMutex(mutex) == 0)
            {
                while (SDL_PollEvent(&e) != 0)
                {
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                    else if (e.type == SDL_KEYDOWN)
                    {
                        //here we detect de number key pressed
                        switch (e.key.keysym.sym)
                        {
                        case SDLK_1:
                        case SDLK_KP_1:
                            lvl = 1;
                            break;
                        case SDLK_2:
                        case SDLK_KP_2:
                            lvl = 2;
                            break;
                        case SDLK_3:
                        case SDLK_KP_3:
                            lvl = 3;
                            break;
                        case SDLK_4:
                        case SDLK_KP_4:
                            lvl = 4;
                            break;
                        case SDLK_5:
                        case SDLK_KP_5:
                            lvl = 5;
                            break;
                        case SDLK_6:
                        case SDLK_KP_6:
                            lvl = 6;
                            break;
                        case SDLK_7:
                        case SDLK_KP_7:
                            lvl = 7;
                            break;
                        case SDLK_8:
                        case SDLK_KP_8:
                            lvl = 8;
                            break;
                        case SDLK_9:
                        case SDLK_KP_9:
                            lvl = 9;
                            break;
                        case SDLK_UP:
                            lvl++;
                            break;
                        case SDLK_DOWN:
                            lvl--;
                            break;
                        case SDLK_0:
                        case SDLK_KP_0:
                        default:
                            lvl = 0;
                            break;
                        }
                        windowManager->Update(lvl);
                        SDL_UnlockMutex(mutex);
                    }
                }
            }
        }
    }
    else
    {
        std::cout << "error initializating sdl" << std::endl;
        SDL_Delay(5000);
    }
    windowManager->Close();
    return 0;
}