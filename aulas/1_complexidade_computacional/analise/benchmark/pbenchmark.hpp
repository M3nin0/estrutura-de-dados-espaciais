#pragma once

#include <string>
#include <chrono>


namespace PBanchmark
{
    struct TimerResult
    {
        double msResult, mlResult;
    };

    class Timer
    {
    public:
        Timer(std::string name);
        ~Timer();

        TimerResult* finish();

        std::string name();
    private:
        std::string p_name;
        std::chrono::time_point<std::chrono::high_resolution_clock> p_StartPointTime;
    };
}
