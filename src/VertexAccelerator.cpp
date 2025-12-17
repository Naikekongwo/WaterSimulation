#include "VertexAccelerator.hpp"

#include "SDL2/SDL.h"

bool VertexAccelerator::startWorker(vector<SDL_Vertex> &Vertices, std::function<void(SDL_Vertex&, float)> ProcessFunc)
{
    if(!threads_.empty())
        return false;
    
    // 线程池不空，直接返回false
    
    int VerticesCount = Vertices.size();

    if(VerticesCount > multiThreadsThreshold)
    {
        // 启动多线程计算
    }
    else
    {
        // 单线程处理
        threads_.push_back(std::async([Vertices.begin(), Range, ProcessFunc](ProcessVertices(Vertices.begin(),ProcessFunc, VerticesCount))));
    }

    
    return true;
}