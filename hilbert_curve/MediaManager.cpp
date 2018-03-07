#include "MediaManager.h"
#include <SDL_image.h>
MediaManager::MediaManager()
{
}

MediaManager::~MediaManager()
{
}

bool MediaManager::loadImage()
{
    return SDL_LoadBMP("img/texture.bmp") != nullptr;
}

SDL_Texture* MediaManager::loadTexture(std::string path, SDL_Renderer* renderer)
{
    SDL_Texture* retVal = nullptr;
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (surface != nullptr)
    {
        retVal = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
    }
    return retVal;
}

void MediaManager::destroyImage()
{
}