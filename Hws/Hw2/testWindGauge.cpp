#include <iostream>
#include <deque>
#include "WindGauge.h"

int main()
{
    Windgauge A;
    A.currentWindSpeed(15);
    A.currentWindSpeed(16);
    A.currentWindSpeed(12);
    A.currentWindSpeed(15);
    A.currentWindSpeed(15);
    // A.print();
    A.dump();
    A.currentWindSpeed(16);
    A.currentWindSpeed(17);
    A.currentWindSpeed(16);
    A.currentWindSpeed(16);
    A.currentWindSpeed(20);
    A.currentWindSpeed(17);
    A.currentWindSpeed(16);
    A.currentWindSpeed(15);
    A.currentWindSpeed(16);
    A.currentWindSpeed(20);
    A.dump();

    return 0;
}