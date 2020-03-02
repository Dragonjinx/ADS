#include <deque>
#include <iostream>
#include "WindGauge.h"

using namespace std;

WindGauge::WindGauge(int period = 12){
    this->period = period;
}

void WindGauge::currentWindSpeed(int speed){
    if(size == period)
        speeds.pop_front();
    speeds.push_back(speed);
    if(size < period)
        size++;
}

int WindGauge::highest() const{
    if(size == 0){
        cout << "Invalid request, no data stored.\n";
        return 0;
    }
    std::deque<int>::const_iterator i = speeds.begin();
    int max = *i;
    for(int count = 0; count < size; count++){
        if(*i > max)
            max = *i;
        i++;
    }
    return max;
}

int WindGauge::lowest() const{
    if(size == 0){
        cout << "Invalid request, no data stored.\n";
        return 0;
    }
    std::deque<int>::const_iterator i = speeds.begin();
    int min = *i;
    for(int count = 0; count < size; count++){
        if(*i < min)
            min = *i;
        i++;
    }
    return min;
}

int WindGauge::average() const{
    if(size == 0){
        cout << "Invalid request, no data stored.\n";
        return 0;
    }
    std::deque<int>::const_iterator i = speeds.begin();
    int average = 0;
    for(int count = 0; count < size; count++){
        average = average + (*i)/size;
        i++;
    }
    return average;
}

void WindGauge::dump() const{
    cout << "The highest speed is " << highest() << endl;
    cout << "The lowest speed is " << lowest() << endl;
    cout << "The average speed is " << average() << endl;
}