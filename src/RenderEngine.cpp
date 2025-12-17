#include "RenderEngine.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>

#include "Timer.hpp"

// 进行具体的实现


bool RenderEngine::InitialSDL()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        // 初始化失败了
        return false;
    }

    IMG_Init(IMG_INIT_PNG);

    // 创建窗口

    SDL_CreateWindowAndRenderer(1280, 720, SDL_WINDOW_SHOWN, &window, &renderer);

    if(!window || !renderer)
    {
        // 创建失败了
        return false;
    }

    SDL_SetWindowTitle(window, "Waterwaves Simulator");

    SDL_SetWindowResizable(window, SDL_FALSE);

    // 设置一些属性

    return true;
}

bool RenderEngine::LoadResource()
{
    SDL_Surface* water_texture = IMG_Load("water.png");
    // 读取贴图

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, water_texture);
    // 转换为纹理

    if(!texture)
    {
        // 如果为空
        return false;
    }

    Textures[0] = texture;
    // 将纹理注册到Unordered_map之中

    return true;
}

bool RenderEngine::Mainloop()
{
    bool should_close = false;

    SDL_Event event;

    timer = new Timer(30);

    while(!should_close)
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    should_close = true;
                    break;
                default:
                    break;                
            }
            // 事件处理完毕
        }
        // 等待函数

        timer->TimeTicks();

        SDL_RenderPresent(renderer);
        // 刷新帧数
    }
    return true;
}


void RenderEngine::CleanUp()
{
    if(timer) delete(timer);

    if(!Textures.empty())
    {
        for(auto it = Textures.begin(); it != Textures.end(); it++)
        {
            auto now = it->second;
            SDL_DestroyTexture(now);

            it = Textures.erase(it);
        }
    }

    if(window) SDL_DestroyWindow(window);

    if(renderer) SDL_DestroyRenderer(renderer);

    SDL_Quit();
}