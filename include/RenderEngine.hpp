#ifndef _RENDER_ENGINE_H_
#define _RENDER_ENGINE_H_

#include "SDL2/SDL.h"
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_render.h>
#include <unordered_map>

using Window = SDL_Window;
using Renderer = SDL_Renderer;

class Timer;

class RenderEngine
{
    public:

    void StartUp()
    {
        if(!InitialSDL())
        {
            SDL_Log("Failed to initial SDL.");
            return;
        }

        if(!LoadResource())
        {
            SDL_Log("Failed to load resources.");
            return;
        }

        if(!Mainloop())
        {
            SDL_Log("Exit loop function with bad return value");
            return;
        }

        CleanUp();
    }

    protected:
    
    bool InitialSDL();
    bool LoadResource();
    bool Mainloop();
    void CleanUp();

    private:

    Window* window;
    Renderer* renderer;

    std::unordered_map<uint8_t, SDL_Texture*> Textures;

    Timer* timer;
};

#endif //_RENDER_ENGINE_H_