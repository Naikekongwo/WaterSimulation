#ifndef _VERTEX_ACCELERATOR_H_
#define _VERTEX_ACCELERATOR_H_

// 顶点加速器

#include <future>
#include <vector>

static constexpr int multiThreadsThreshold = 2000;
static constexpr int idealVerticesPerThread = 500;

static constexpr float multiThreadsFactor = 1.0f;

// multiThreadsThreshold : 单核阈值，达到此阈值启动超线程
// idelVerticesPerThread : 多线程状态下每个核心分配的顶点
// multiThreadsFactor : 多线程因数

using std::vector;
using std::future;

class SDL_Vertex;

bool ProcessVertices(vector<SDL_Vertex>::iterator starter, std::function<void(SDL_Vertex&, float)> ProcessFunc, int Range);

class VertexAccelerator
{
    public:

    bool startWorker(vector<SDL_Vertex> &Vertices, std::function<void(SDL_Vertex&, float)> ProcessFunc);

    // 开始加速

    private:

    vector<future<void>> threads_;

    // threads_ 线程池

};

#endif //_VERTEX_ACCELERATOR_H_