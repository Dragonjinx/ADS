#include <iostream>
#include "WindGauge.h"

Windgauge::Windgauge(int period)
{
    Storage.resize(period);
    Storage.clear();
}

int Windgauge::highest() const
{
    int size = Storage.size();
    int max = Storage[0];
    for(int i = 0; i < size; i++)
    {
        if(Storage[i] > max)
        {
            max = Storage[i];
        }
    }
    return max;
}

int Windgauge::lowest() const
{
    int size = Storage.size();
    int min = Storage[0];
    for(int i = 0; i < size; i++)
    {
        if(Storage[i] < min)
        {
            min = Storage[i];
        }
    }
    return min;
}

int Windgauge::average() const
{
    int size = Storage.size();
    return ((lowest() + highest()) / size);
}

void Windgauge::currentWindSpeed(int speed)
{
    Storage.push_back(speed);
}

void Windgauge::dump()
{
    std::cout << "Lowest = " << lowest() << std::endl <<\
    "Highest = " << highest() << std::endl <<\
    "Average = " << average() << std::endl; 
}
// Debugging
void Windgauge::print() const
{
    for(int i = 0; i < (int)Storage.size(); i++)
    {
        std::cout << Storage[i] << ' ';
    }
    std::cout << std::endl;
}
