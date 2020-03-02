#include <deque>
#include <iostream>

class WindGauge {
  public:
    WindGauge(int period = 12);
    void currentWindSpeed(int speed);
    int highest() const;
    int lowest() const;
    int average() const;
    void dump() const;
  private:
    std::deque<int> speeds;
    int size = 0;
    int period = 12;
};