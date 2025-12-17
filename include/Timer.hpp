#ifndef _TIMER_H_
#define _TIMER_H_

#include <chrono>
#include <thread>

class Timer
{
    public:

    Timer(uint8_t targetFPS)
    {
        // 先转换间隔的时间为float型
        float DelayTime = 1000.0f / static_cast<int>(targetFPS);

        targetDelayTime = std::chrono::milliseconds(static_cast<int>(DelayTime));
        // 初始化间隔时间

        lastTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
        // 初始化当前的时间
    }

    void Reset()
    {
        lastTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    }

    int GetElapsedTime()
    {
        auto now = std::chrono::system_clock::now();

        auto currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());

        return static_cast<int>((currentTime - lastTime).count());
    }

    void TimeTicks()
    {
        auto Delayers = GetElapsedTime();

        auto now = std::chrono::system_clock::now();
        
        auto currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(
            now.time_since_epoch());
        
        // 计算经过的时间
        auto elapsed = currentTime - lastTime;

        if(Delayers < targetDelayTime.count() )
        {
            std::this_thread::sleep_for(elapsed);
        }
    }

    private:
    
    std::chrono::milliseconds lastTime;
    // 上一次记录的时间

    std::chrono::milliseconds targetDelayTime;
    // 目标的间隔时间
};

#endif //_TIMER_H_