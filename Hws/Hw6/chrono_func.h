#include <chrono>
#include <iostream>

typedef std::chrono::duration <double, std::ratio<1L, 1000l>> mili;

void print_time(std::ostream& out, std::chrono::duration <double, std::ratio<1L, 1000L>> differnce)
{
    out <<  (differnce).count() << std::endl;
}

std::chrono::time_point<std::chrono::steady_clock> time_now()
{
    return std::chrono::steady_clock::now();
}
