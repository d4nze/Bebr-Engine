#pragma once
#include <chrono>

class Timer
{
public:
    Timer()
    {
        Reset();
    }

public:
    void Reset()
    {
        m_startTime = std::chrono::high_resolution_clock::now();
    }
    float GetDeltaTime()
    {
        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float, std::chrono::seconds::period> deltaTime = currentTime - m_startTime;
        Reset();
        return deltaTime.count();
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_startTime;
};
