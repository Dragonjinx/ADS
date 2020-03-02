#include <deque>
class Windgauge
{
private:
    std::deque<int> Storage;

public:
    Windgauge(int period = 12);
    void currentWindSpeed(int speed);
    int highest() const;
    int lowest() const;
    int average() const;
    void dump();
    void print() const;
};