#include "pbenchmark.hpp"

#include <chrono>
#include <string>

#include <fstream>


PBanchmark::Timer::Timer(std::string name)
{
    this->p_name = name;
    this->p_StartPointTime = std::chrono::high_resolution_clock::now();        
}

PBanchmark::Timer::~Timer()
{
    PBanchmark::TimerResult* tr = finish();

    std::ofstream outFile;
    std::ifstream ifFile("timertests.csv");
    outFile.open("timertests.csv", std::ios::app);
    
    if (!ifFile.good()) // verify file 'exists'
        outFile << "test_name;" << "timing_ml;" << "timing_ms\n";
    outFile << this->p_name << ";" << tr->mlResult << ";" << tr->msResult << std::endl  ;
    outFile.close();
}

PBanchmark::TimerResult* PBanchmark::Timer::finish()
{
    auto endPointTime = std::chrono::high_resolution_clock::now();

    // Define more precision
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(p_StartPointTime).time_since_epoch().count();
    auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endPointTime).time_since_epoch().count();

    TimerResult* tr = new TimerResult;
    tr->mlResult = end - start;
    tr->msResult = tr->mlResult * .001;

    return tr;
}
