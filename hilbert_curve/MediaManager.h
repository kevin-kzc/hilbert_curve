#pragma once
#include <SDL.h>
#include <string>
class MediaManager
{
public:
    MediaManager();
    ~MediaManager();
    bool loadImage();
    void destroyImage();
    SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer);
private:

};
